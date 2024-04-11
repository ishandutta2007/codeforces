#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#include<inttypes.h>

typedef int64_t i64;
typedef int32_t i32;

static void print_int(i64 n){if(n<0){putchar('-');n=-n;}if(n==0){putchar('0');return;}int s[20],len=0;while(n>0){s[len++]=n%10+'0';n/=10;}while(len>0){putchar(s[--len]);}}
static i64 read_int(void){int prev='\0';int c=getchar();while(!('0'<=c && c<='9')){prev=c;c=getchar();}i64 res=0;while('0'<=c && c<='9'){res=10*res+c-'0';c=getchar();}return prev=='-'?-res:res;}

typedef struct range {
  i32 l, r;
  i32 index;
} range;

int cmp (const void *a, const void *b) {
  range *p = (range *)a;
  range *q = (range *)b;
  if (p->l != q->l) return p->l < q->l ? -1 : 1;
  i32 d = p->r - q->r;
  return d == 0 ? 0 : d > 0 ? -1 : 1;
}

void run (void) {
  i32 t = read_int();
  range *p = (range *) calloc (100000, sizeof (range));
  i32 *ans = (i32 *) calloc (100000, sizeof (i32));
  while (t--) {
    i32 n = read_int();
    for (i32 i = 0; i < n; ++i) {
      p[i].l = read_int();
      p[i].r = read_int();
      p[i].index = i;
    }
    qsort (p, n, sizeof (range), cmp);
    i32 max = p[0].r;
    i32 k = 1;
    while (k < n && p[k].l <= max) {
      if (max < p[k].r) {
	max = p[k].r;
      }
      ++k;
    }
    if (k >= n) {
      puts ("-1");
    } else {
      for (i32 i = 0; i < n; ++i) {
	ans[p[i].index] = i < k ? 1 : 2;
      }
      print_int (ans[0]);
      for (i32 i = 1; i < n; ++i) {
	putchar(' ');
	print_int (ans[i]);
      }
      puts("");
    }
  }
}

int main (void) {
  run ();
  return 0;
}