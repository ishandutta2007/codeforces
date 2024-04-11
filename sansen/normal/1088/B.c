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
  const i32 n = read_int();
  const i32 k = read_int();
  i32 *a = (i32 *) calloc (n, sizeof (i32));
  for (i32 i = 0; i < n; ++i) {
    a[i] = read_int();
  }
  qsort (a, n, sizeof (i32), cmp);
  i32 len = 1;
  for (i32 i = 1; i < n; ++i) {
    if (a[i] == a[len - 1]) continue;
    a[len++] = a[i];
  }
  print_int (a[0]);
  putchar('\n');
  for (i32 i = 1; i < k; ++i) {
    if (i < len) {
      printf ("%" PRIi32 "\n", a[i] - a[i - 1]);
      //print_int(a[i] - a[i - 1]);
      //putchar('\n');
    } else {
      puts("0");
    }
  }
}

int main (void) {
  run ();
  return 0;
}