#include <bits/stdc++.h>
#define sz(x) (int((x).size()))
#define pb push_back
#define eb emplace_back
#define all(x) (x).begin(), (x).end()
template<typename T> bool domax(T &a, T b) { return (b > a ? (a = b, true) : false); }
template<typename T> bool domin(T &a, T b) { return (b < a ? (a = b, true) : false); }
typedef long long ll;

struct node_t {
    int next, prev, delta;
};

const int maxn = 500*1000+5;

int n, m, p, nodes = 1, ptr;
node_t node[maxn];
char s[maxn];

void addnode(int delta) {
    node[nodes] = {nodes+1, nodes-1, delta};
    nodes++;
}

int main() {
    scanf("%d%d%d", &n, &m, &p);
    scanf(" %s", s);
    node[0].next = 1;
    for (int i = 0; i < n; i++) {
        addnode(s[i] == '(' ? 1 : -1);
        if (i+1 == p) ptr = nodes-1;
    }
    node[nodes].prev = nodes-1;
    scanf(" %s", s);
    for (int i = 0; i < m; i++) {
        if (ptr == 0 || ptr == nodes) {
            printf("\n");
            return 0;
        }
        if (s[i] == 'L') {
            if (node[ptr].prev != 0) ptr = node[ptr].prev;
        } else if (s[i] == 'R') {
            if (node[ptr].next != nodes) ptr = node[ptr].next;
        } else {
            if (node[ptr].delta == 1) {
                int end = node[ptr].next, count = 1;
                while (count) {
                    count += node[end].delta;
                    end = node[end].next;
                }
                node[end].prev = node[ptr].prev;
                node[node[end].prev].next = end;
                ptr = end;
                if (ptr == nodes) ptr = node[end].prev;
            } else {
                int end = node[ptr].prev, count = -1;
                while (count) {
                    count += node[end].delta;
                    end = node[end].prev;
                }
                node[end].next = node[ptr].next;
                node[node[end].next].prev = end;
                ptr = node[end].next;
                if (ptr == nodes) ptr = end;
            }
        }
    }
    ptr = node[0].next;
    while (ptr != nodes) {
        printf("%c", node[ptr].delta == 1 ? '(' : ')');
        ptr = node[ptr].next;
    }
    printf("\n");
}