#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#include<inttypes.h>

typedef int64_t i64;
typedef int32_t i32;

static void print_int(i64 n){if(n<0){putchar('-');n=-n;}if(n==0){putchar('0');return;}int s[20],len=0;while(n>0){s[len++]=n%10+'0';n/=10;}while(len>0){putchar(s[--len]);}}
static i64 read_int(void){int prev='\0';int c=getchar();while(!('0'<=c && c<='9')){prev=c;c=getchar();}i64 res=0;while('0'<=c && c<='9'){res=10*res+c-'0';c=getchar();}return prev=='-'?-res:res;}

int cmp (const void *a, const void *b) {
  i32 d = *(i32 *)a - *(i32 *)b;
  return d == 0 ? 0 : d < 0 ? -1 : 1;
}

void run (void) {
  i32 n = read_int();
  i32 *a = (i32 *) calloc (n, sizeof (i32));
  for (i32 i = 0; i < n; ++i) {
    a[i] = read_int();
  }
  qsort (a, n, sizeof (i32), cmp);
  i32 *ans = (i32 *) calloc (2 * n, sizeof (i32));
  i32 len[2] = {0, 0};
  for (i32 i = 0; i < n; ++i) {
    if (len[0] == 0 || ans[len[0] - 1] != a[i]) {
      ans[len[0]++] = a[i];
    } else if (len[1] == 0 || ans[n + len[1] - 1] != a[i]) {
      ans[n + len[1]++] = a[i];
    } else {
      puts("NO");
      return;
    }
  }
  puts("YES");
  print_int (len[0]);
  puts("");
  for (i32 i = 0; i < len[0]; ++i) {
    print_int (ans[i]);
    if (i + 1 < len[0]) putchar (' ');
  }
  puts("");
  print_int (len[1]);
  puts("");
  for (i32 i = 0; i < len[1]; ++i) {
    print_int (ans[n + len[1] - 1 - i]);
    if (i + 1 < len[1]) putchar (' ');
  }
  puts("");
}

int main (void) {
  run ();
  return 0;
}