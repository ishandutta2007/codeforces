#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#include<inttypes.h>

typedef int64_t i64;
typedef int32_t i32;

static i64 read_int(void){int prev='\0';int c=getchar();while(!('0'<=c && c<='9')){prev=c;c=getchar();}i64 res=0;while('0'<=c && c<='9'){res=10*res+c-'0';c=getchar();}return prev=='-'?-res:res;}

void run (void) {
  i32 n = read_int();
  char *s = (char *) calloc (n + 1, sizeof (char));
  scanf ("%s", s);
  i32 *f = (i32 *) calloc (10, sizeof (i32));
  for (i32 i = 1; i < 10; ++i) {
    f[i] = read_int();
  }
  i32 i = 0;
  for (; i < n; ++i) {
    i32 k = s[i] - '0';
    if (f[k] > k) {
      break;
    }
  }
  for (; i < n; ++i) {
    i32 k = s[i] - '0';
    if (f[k] < k) {
      break;
    }
    s[i] = '0' + f[k];
  }
  puts (s);
}

int main (void) {
  run ();
  return 0;
}