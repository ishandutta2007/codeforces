#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#include<string.h>

typedef int64_t i64;
typedef int32_t i32;

static void print_int(i64 n){if(n<0){putchar('-');n=-n;}if(n==0){putchar('0');return;}int s[20],len=0;while(n>0){s[len++]=n%10+'0';n/=10;}while(len>0){putchar(s[--len]);}}
static i64 read_int(void){int prev='\0';int c=getchar();while(!('0'<=c && c<='9')){prev=c;c=getchar();}i64 res=0;while('0'<=c && c<='9'){res=10*res+c-'0';c=getchar();}return prev=='-'?-res:res;}

#define MIN(a,b) ((a)<(b)?(a):(b))
#define ALLOC(size,type) ((type*)calloc((size),sizeof(type)))

void run (void) {
  i32 q = read_int();
  char *s = ALLOC (200000 + 1, char);
  i32 *a = ALLOC (200000 + 1, i32);
  i32 *b = ALLOC (200000 + 1, i32);
  while (q--) {
    i32 n = read_int();
    i32 k = read_int();
    scanf ("%s", s);
    char rgb[] = "RGB";
    for (i32 i = 0; i < n; ++i) {
      for (i32 j = 0; j < 3; ++j) {
        if (s[i] == rgb[j]) {
          a[i] = j;
        }
      }
    }
    i32 ans = k;
    for (i32 s = 0; s < 3; ++s) {
      for (i32 i = 0; i < n; ++i) {
        if (a[i] == (s + i) % 3) {
          b[i] = 1;
        } else {
          b[i] = 0;
        }
      }
      b[n] = 0;
      for (i32 i = n - 1; i >= 0; --i) {
        b[i] += b[i + 1];
      }
      for (i32 i = 0; i + k <= n; ++i) {
        i32 v = k - (b[i] - b[i + k]);
        ans = MIN (ans, v);
      }
    }
    print_int (ans);
    puts ("");
  }
}

int main (void) {
  run ();
  return 0;
}