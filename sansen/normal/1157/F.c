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
  const i32 m = 200000;
  i32 *cnt = (i32 *) calloc (m + 1, sizeof (i32));
  while (n--) {
    i32 h = read_int();
    cnt[h]++;
  }
  i32 max = 0;
  i32 maxl = 0;
  i32 maxr = 0;
  for (i32 l = 1; l <= m;) {
    if (cnt[l] == 0) {
      l++;
      continue;
    }
    i32 sum = cnt[l];
    i32 r = l + 1;
    while (r <= m && cnt[r] >=2) {
      sum += cnt[r];
      r++;
    }
    if (r <= m && cnt[r] == 1) {
      sum++;
    }
    if (max < sum) {
      max = sum;
      maxl = l;
      maxr = r;
    }
    l = r;
  }
  print_int (max);
  puts("");
  i32 l = maxl;
  i32 r = maxr;
  for (i32 i = l + 1; i < r; ++i) {
    while (cnt[i] > 1) {
      print_int (i);
      putchar (' ');
      cnt[i]--;
    }
  }
  for (i32 i = r; i > l; --i) {
    while (cnt[i]--) {
      print_int (i);
      putchar (' ');
    }
  }
  while (cnt[l] > 1) {
    print_int (l);
    putchar (' ');
    cnt[l]--;
  }
  print_int (l);
  puts("");
}

int main (void) {
  run ();
  return 0;
}