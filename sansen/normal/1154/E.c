#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#include<inttypes.h>
#include<string.h>

typedef int64_t i64;
typedef int32_t i32;

static void print_int(i64 n){if(n<0){putchar('-');n=-n;}if(n==0){putchar('0');return;}int s[20],len=0;while(n>0){s[len++]=n%10+'0';n/=10;}while(len>0){putchar(s[--len]);}}
static i64 read_int(void){int prev='\0';int c=getchar();while(!('0'<=c && c<='9')){prev=c;c=getchar();}i64 res=0;while('0'<=c && c<='9'){res=10*res+c-'0';c=getchar();}return prev=='-'?-res:res;}

#define ALLOC(size,type) ((type*)calloc((size),sizeof(type)))
#define SORT(a,n,cmp) msort((a),(n),sizeof(*(a)),cmp)

typedef struct double_linked_list {
  i32 k;
  struct double_linked_list *left, *right;
} list;

void run (void) {
  i32 n = read_int();
  i32 k = read_int();
  i32 *p = ALLOC (n, i32);
  for (i32 i = 0; i < n; ++i) {
    p[read_int() - 1] = i;
  }
  list *lst = ALLOC (n, list);
  for (i32 i = 0; i < n; ++i) {
    lst[i].k = i;
    if (i + 1 < n) lst[i].right = lst + i + 1;
    if (i - 1 >= 0) lst[i].left = lst + i - 1;
  }
  uint8_t *ans = ALLOC (n, uint8_t);
  for (i32 i = n - 1, x = 1; i >= 0; --i) {
    i32 v = p[i];
    if (ans[v] > 0) continue;
    ans[v] = x;
    list *t = lst + v;
    list *l = t->left;
    for (i32 j = 0; j < k && l != NULL; ++j) {
      ans[l->k] = x;
      l = l->left;
    }
    list *r = t->right;
    for (i32 j = 0; j < k && r != NULL; ++j) {
      ans[r->k] = x;
      r = r->right;
    }
    x ^= 1 ^ 2;
    if (l != NULL) {
      l->right = r;
    }
    if (r != NULL) {
      r->left = l;
    }
  }
  for (i32 i = 0; i < n; ++i) {
    print_int (ans[i]);
  }
  puts ("");
}

int main (void) {
  run ();
  return 0;
}