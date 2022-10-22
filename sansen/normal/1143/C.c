#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#include<inttypes.h>

typedef int32_t i32;
typedef int64_t i64;

static void print_int(i64 n){if(n<0){putchar('-');n=-n;}if(n==0){putchar('0');return;}int s[20],len=0;while(n>0){s[len++]=n%10+'0';n/=10;}while(len>0){putchar(s[--len]);}}
static i64 read_int(void){int prev='\0';int c=getchar();while(!('0'<=c && c<='9')){prev=c;c=getchar();}i64 res=0;while('0'<=c && c<='9'){res=10*res+c-'0';c=getchar();}return prev=='-'?-res:res;}

void run (void) {
  const i32 n = read_int();
  i32 *p = (i32 *) calloc (n + 1, sizeof (i32));
  i32 *c = (i32 *) calloc (n + 1, sizeof (i32));
  i32 *cond = (i32 *) calloc (n + 1, sizeof (i32));
  for (i32 i = 1; i <= n; ++i) {
    cond[i] = 1;
  }
  for (i32 i = 1; i <= n; ++i) {
    p[i] = read_int();
    c[i] = read_int();
    if (p[i] != -1 && c[i] == 0) {
      cond[p[i]] = 0;
    }
  }
  i32 cnt = 0;
  for (i32 i = 1; i <= n; ++i) {
    if (c[i] == 1 && cond[i] == 1) {
      if (cnt > 0) {
	putchar(' ');
      }
      print_int (i);
      cnt++;
    }
  }
  if (cnt == 0) {
    print_int (-1);
  }
  putchar('\n');
}

int main (void) {
  run ();
  return 0;
}