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
  i32 row = read_int();
  i32 col = read_int();
  i32 *a = (i32 *) calloc (2 * row * col, sizeof (i32));
  i32 *b = a + row * col;
  for (i32 i = 0; i < 2 * row * col; ++i) {
    a[i] = read_int();
  }
  i32 *c = (i32 *) calloc (row + col, sizeof (i32));
  i32 *d = (i32 *) calloc (row + col, sizeof (i32));
  for (i32 i = 0; i < row + col - 1; ++i) {
    i32 len = 0;
    for (i32 j = 0, k = i; j <= i; ++j, --k) {
      if (0 <= j && j < row && 0 <= k && k < col) {
	c[len] = a[j * col + k];
	d[len] = b[j * col + k];
	len++;
      }
    }
    qsort (c, len, sizeof (i32), cmp);
    qsort (d, len, sizeof (i32), cmp);
    for (i32 j = 0; j < len; ++j) {
      if (c[j] != d[j]) {
	puts("NO");
	return;
      }
    }
  }
  puts("YES");
}

int main (void) {
  run ();
  return 0;
}