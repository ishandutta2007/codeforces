#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#include<inttypes.h>

typedef int64_t i64;
typedef int32_t i32;

static void print_int(i64 n){if(n<0){putchar('-');n=-n;}if(n==0){putchar('0');return;}int s[20],len=0;while(n>0){s[len++]=n%10+'0';n/=10;}while(len>0){putchar(s[--len]);}}
static i64 read_int(void){int prev='\0';int c=getchar();while(!('0'<=c && c<='9')){prev=c;c=getchar();}i64 res=0;while('0'<=c && c<='9'){res=10*res+c-'0';c=getchar();}return prev=='-'?-res:res;}

#define POS(i,j) ((i) * n + (j))

void run (void) {
  i32 m = read_int();
  i32 n = read_int();
  i32 *a = (i32 *) calloc (2 * m * n, sizeof (i32));
  i32 *b = a + m * n;
  for (i32 i = 0; i < 2 * m * n; ++i) {
    a[i] = read_int();
  }
  for (i32 i = 0; i + 1 < m; ++i) {
    for (i32 j = 0; j + 1 < n; ++j) {
      if (a[POS(i,j)] != b[POS(i,j)]) {
	i32 d[] = {0,0,1,1,0};
	for (i32 k = 0; k < 4; ++k) {
	  a[POS(i + d[k], j + d[k + 1])] ^= 1;
	}
      }
    }
  }
  for (i32 i = 0; i < m; ++i) {
    for (i32 j = 0; j < n; ++j) {
      if (a[POS(i,j)] != b[POS(i,j)]) {
	puts("No");
	return;
      }
    }
  }
  puts("Yes");
}

int main (void) {
  run ();
  return 0;
}