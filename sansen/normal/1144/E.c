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

void run (void) {
  i32 n = read_int();
  char *s = (char *) calloc (n + 1, sizeof (char));
  char *t = (char *) calloc (n + 1, sizeof (char));
  scanf ("%s", s);
  scanf ("%s", t);
  i32 *d = (i32 *) calloc (n, sizeof (i32));
  const i32 p = 26;
  for (i32 i = 0; i < n; ++i) {
    d[i] = t[i] - s[i];
  }
  for (i32 i = n - 1; i >= 0; --i) {
    if (d[i] < 0) {
      i32 j;
      for (j = i - 1; d[j] == 0; --j);
      d[j]--;
      for (j++; j < i; ++j) {
	d[j] = p - 1;
      }
      d[i] += p;
    }
    while (d[i] >= p) {
      d[i] -= p;
      d[i + 1]++;
    }
  }
  for (i32 i = 0; i < n; ++i) {
    if (d[i] % 2 == 1) {
      d[i + 1] += p;
    }
    d[i] /= 2;
  }
  i32 carry = 0;
  for (i32 i = n - 1; i >= 0; --i) {
    i32 c = s[i] - 'a' + d[i] + carry;
    carry = 0;
    if (c >= p) {
      carry = 1;
      c -= p;
    }
    t[i] = c + 'a';
  }
  puts(t);
}

int main (void) {
  run ();
  return 0;
}