#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#include<inttypes.h>

typedef int64_t i64;
typedef int32_t i32;

static void print_int(i64 n){if(n<0){putchar('-');n=-n;}if(n==0){putchar('0');return;}int s[20],len=0;while(n>0){s[len++]=n%10+'0';n/=10;}while(len>0){putchar(s[--len]);}}
static i64 read_int(void){int prev='\0';int c=getchar();while(!('0'<=c && c<='9')){prev=c;c=getchar();}i64 res=0;while('0'<=c && c<='9'){res=10*res+c-'0';c=getchar();}return prev=='-'?-res:res;}

#define ALLOC(size,type) ((type*)calloc((size),sizeof(type)))

void run (void) {
  i32 n = read_int();
  i32 m = read_int();
  i32 *t = ALLOC (3 * m, i32);
  i32 *l = t + m;
  i32 *r = l + m;
  for (i32 i = 0; i < m; ++i) {
    t[i] = read_int();
    l[i] = read_int() - 1;
    r[i] = read_int();
  }
  uint8_t *cond = ALLOC (n, uint8_t);
  for (i32 i = 0; i < m; ++i) {
    if (t[i] == 0) continue;
    for (i32 j = l[i]; j < r[i] - 1; ++j) {
      cond[j] = 1;
    }
  }
  for (i32 i = 0; i < m; ++i) {
    if (t[i] == 1) continue;
    i32 ok = 0;
    for (i32 j = l[i]; j < r[i] - 1; ++j) {
      if (cond[j] == 0) {
        ok = 1;
      }
    }
    if (!ok) {
      puts ("NO");
      return;
    }
  }
  puts ("YES");
  i32 v = 10000;
  print_int (v);
  for (i32 i = 1; i < n; ++i) {
    if (cond[i - 1] == 0) {
      --v;
    }
    putchar (' ');
    print_int (v);
  }
  puts ("");
}

int main (void) {
  run ();
  return 0;
}