#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#include<inttypes.h>

typedef int64_t i64;
typedef int32_t i32;

static void print_int(i64 n){if(n<0){putchar('-');n=-n;}if(n==0){putchar('0');return;}int s[20],len=0;while(n>0){s[len++]=n%10+'0';n/=10;}while(len>0){putchar(s[--len]);}}
static i64 read_int(void){int prev='\0';int c=getchar();while(!('0'<=c && c<='9')){prev=c;c=getchar();}i64 res=0;while('0'<=c && c<='9'){res=10*res+c-'0';c=getchar();}return prev=='-'?-res:res;}

#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))

i32 calc (i32 *a, i32 n) {
  i32 k = 0;
  while (k + 1 < n && a[k] < a[k + 1]) ++k;
  return k + 1;
}

void reverse (i32 *a, i32 n) {
  for (i32 i = 0; i < n - 1 - i; ++i) {
    i32 s = a[i];
    a[i] = a[n - 1 - i];
    a[n - 1 - i] = s;
  }
}

void run (void) {
  i32 n = read_int();
  i32 *a = (i32 *) calloc (n, sizeof (i32));
  for (i32 i = 0; i < n; ++i) {
    a[i] = read_int();
  }
  char *ans = (char *) calloc (n + 1, sizeof (char));
  i32 len = 0;
  i32 prev = 0;
  i32 l = 0;
  i32 r = n - 1;
  while (l <= r) {
    if (a[l] == a[r] && prev < a[l]) {
      i32 x = calc (a + l, r + 1 - l);
      reverse (a + l, r + 1 - l);
      i32 y = calc (a + l, r + 1 - l);
      if (x <= y) {
	while (y--) {
	  ans[len++] = 'R';
	}
      } else {
	while (x--) {
	  ans[len++] = 'L';
	}
      }
      break;
    }
    i32 v = MIN(a[l], a[r]);
    if (prev >= v) {
      v = MAX(a[l], a[r]);
      if (prev >= v) {
	break;
      }
    }
    prev = v;
    if (a[l] == v) {
      l++;
      ans[len++] = 'L';
    } else {
      r--;
      ans[len++] = 'R';
    }
  }
  print_int (len);
  puts ("");
  puts (ans);
}

int main (void) {
  run ();
  return 0;
}