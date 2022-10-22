#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#include<inttypes.h>
#include<string.h>

typedef uint32_t u32;
typedef uint64_t u64;

static void print_int(u64 n){if(n==0)putchar('0');else{int s[20],k=0;while(n){s[k++]=n%10+'0';n/=10;}while(k)putchar(s[--k]);}}

#define F 26
#define ALLOC(size,type) ((type*)calloc((size),sizeof(type)))
#define free(x) ;

typedef struct node {
    u32 cnt;
    struct node *fail;
    struct node *next[F];
} node;

void free_node (node * const p) {
    if (p == NULL) {
        return;
    }
    for (u32 i = 0; i < F; ++i) {
        free_node (p->next[i]);
    }
    free (p);
}

typedef struct aho_corasick {
    node *root;
    char **s;
    u32 max_size;
    u32 size;
    u32 node_cnt;
} aho_corasick;

aho_corasick* new_aho_corasick (void) {
    aho_corasick *res = ALLOC (1, aho_corasick);
    res->root = ALLOC (1, node);
    res->root->fail = res->root;
    res->max_size = 1;
    res->s = ALLOC (1, char *);
    res->node_cnt = 1;
    return res;
}

void free_aho_corasick (aho_corasick *aho) {
    free_node (aho->root);
    free (aho->s);
    free (aho);
}

void insert_aho (aho_corasick *aho, char *s) {
    if (aho->size == aho->max_size) {
        const u32 size = aho->max_size * 2;
        aho->s = (char **) realloc (aho->s, size * sizeof(char *));
        aho->max_size = size;
    }
    aho->s[aho->size++] = s;
    node *p = aho->root;
    for (char *c = s; *c != '\0'; ++c) {
        u32 k = *c - 'a';
        if (NULL == p->next[k]) {
            p->next[k] = ALLOC (1, node);
            aho->node_cnt += 1;
        }
        p = p->next[k];
    }
    p->cnt += 1;
}

void build(aho_corasick *aho) {
    node **que = ALLOC (aho->node_cnt, node *);
    u32 front = 0;
    u32 back = 0;
    node *root = aho->root;
    for (u32 i = 0; i < F; ++i) {
        node *p = root->next[i];
        if (p != NULL) {
            que[back++] = p;
            p->fail = root;
        }
    }
    while (front < back) {
        node *p = que[front++];
        p->cnt += p->fail->cnt;
        for (u32 i = 0; i < F; ++i) {
            node *q = p->next[i];
            if (q == NULL) {
                continue;
            }
            node *fail = p->fail;
            while (fail != root && fail->next[i] == NULL) {
                fail = fail->fail;
            }
            if (fail->next[i] != NULL) {
                q->fail = fail->next[i];
            } else {
                q->fail = root;
            }
            que[back++] = q;
        }
    }
    free (que);
}

u64 find_aho (aho_corasick *aho, char *s) {
    u64 ans = 0;
    node *pos = aho->root;
    char *c = s;
    while (*c != '\0') {
        u32 k = *c++ - 'a';
        while (pos != aho->root && pos->next[k] == NULL) {
            pos = pos->fail;
        }
        if (pos->next[k] != NULL) {
            pos = pos->next[k];
        }
        ans += pos->cnt;
    }
    return ans;
}

typedef struct incremental_aho_corasick {
    aho_corasick **aho;
    u32 len;
} incremental_aho_corasick;

incremental_aho_corasick* new_incremental_aho_corasick (void) {
    incremental_aho_corasick *res = ALLOC (1, incremental_aho_corasick);
    res->aho = ALLOC (32, aho_corasick *);
    res->len = 0;
    return res;
}

void insert (incremental_aho_corasick *inc_aho, char *s) {
    aho_corasick *aho = new_aho_corasick();
    insert_aho(aho, s);
    build (aho);
    while (inc_aho->len > 0 && inc_aho->aho[inc_aho->len - 1]->size == aho->size) {
        aho_corasick *p = inc_aho->aho[--inc_aho->len];
        aho_corasick *next = new_aho_corasick();
        for (u32 i = 0; i < p->size; ++i) {
            insert_aho (next, p->s[i]);
        }
        for (u32 i = 0; i < aho->size; ++i) {
            insert_aho (next, aho->s[i]);
        }
        build (next);
        free_aho_corasick (p);
        free_aho_corasick (aho);
        aho = next;
    }
    inc_aho->aho[inc_aho->len++] = aho;
}

u64 find (incremental_aho_corasick *inc_aho, char *s) {
    u64 ans = 0;
    for (u32 i = 0; i < inc_aho->len; ++i) {
        ans += find_aho (inc_aho->aho[i], s);
    }
    return ans;
}

void run (void) {
    u32 m;
    scanf ("%" SCNu32, &m);
    char *buf = ALLOC (600000 + 1, char);
    incremental_aho_corasick *add = new_incremental_aho_corasick();
    incremental_aho_corasick *del = new_incremental_aho_corasick();
    while (m--) {
        u32 op;
        scanf ("%" SCNu32 "%s", &op, buf);
        char *s = buf;
        buf += strlen (s) + 1;
        if (op == 1) {
            insert (add, s);
        } else if (op == 2) {
            insert (del, s);
        } else {
            u64 ans = find (add, s) - find (del, s);
            print_int(ans);
            puts ("");
            fflush (stdout);
        }
    }
}

int main (void) {
    run();
    return 0;
}