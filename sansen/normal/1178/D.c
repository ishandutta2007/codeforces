#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#include<inttypes.h>
#include<math.h>
#include<string.h>

typedef int64_t i64;
typedef int32_t i32;

static void print_int(i64 n){if(n<0){putchar('-');n=-n;}if(n==0){putchar('0');return;}int s[20],len=0;while(n>0){s[len++]=n%10+'0';n/=10;}while(len>0){putchar(s[--len]);}}
static i64 read_int(void){int prev='\0';int c=getchar();while(!('0'<=c && c<='9')){prev=c;c=getchar();}i64 res=0;while('0'<=c && c<='9'){res=10*res+c-'0';c=getchar();}return prev=='-'?-res:res;}

#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define ABS(a) ((a)>(0)?(a):-(a))
#define ALLOC(size,type) ((type*)calloc((size),sizeof(type)))
#define SORT(a,n,cmp) msort((a),(n),sizeof(*(a)),cmp)

int is_prime (i32 n) {
  if (n <= 1) return 0;
  for (i32 k = 2; k * k <= n; ++k) {
    if (n % k == 0) return 0;
  }
  return 1;
}

void test (void) {
  for (i32 n = 3; n <= 1000; ++n) {
    if (is_prime (n)) continue;
    i32 e = n + 1;
    while (!is_prime (e)) ++e;
    i32 d = e - n;
    printf ("%" PRIi32 " %" PRIi32 "\n", n, e);
    if (2 * d > n) {
      printf ("%" PRIi32 "\n", n);
    }
  }
}

void run (void) {
  i32 n = read_int();
  i32 e = n;
  while (!is_prime (e)) ++e;
  print_int (e);
  puts ("");
  for (i32 i = 1; i <= n; ++i) {
    print_int (i);
    putchar (' ');
    print_int (i + 1 <= n ? i + 1 : 1);
    puts ("");
    e--;
  }
  for (i32 i = 1; e > 0; ++i, --e) {
    print_int (i);
    putchar (' ');
    print_int (i + n / 2);
    puts ("");
  }
}

int main (void) {
  run ();
  return 0;
}