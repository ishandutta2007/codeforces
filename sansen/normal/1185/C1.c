#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>

typedef int64_t i64;
typedef int32_t i32;

static void print_int(i64 n){if(n<0){putchar('-');n=-n;}if(n==0){putchar('0');return;}int s[20],len=0;while(n>0){s[len++]=n%10+'0';n/=10;}while(len>0){putchar(s[--len]);}}
static i64 read_int(void){int prev='\0';int c=getchar();while(!('0'<=c && c<='9')){prev=c;c=getchar();}i64 res=0;while('0'<=c && c<='9'){res=10*res+c-'0';c=getchar();}return prev=='-'?-res:res;}

#define ALLOC(size,type) ((type*)calloc((size),sizeof(type)))

void run (void) {
  i32 n = read_int();
  i32 m = read_int();
  i32 *t = ALLOC (n, i32);
  for (i32 i = 0; i < n; ++i) {
    t[i] = read_int();
  }
  i32 *cnt = ALLOC (100 + 1, i32);
  i32 sum = 0;
  for (i32 i = 0; i < n; ++i) {
    if (sum + t[i] <= m) {
      print_int (0);
      putchar (i == n - 1 ? '\n' : ' ');
    } else {
      i32 s = sum;
      i32 k = 100;
      i32 ans = 0;
      while (s + t[i] > m) {
        ans += cnt[k];
        s -= cnt[k] * k;
        k--;
      }
      k++;
      ans -= (m - s - t[i]) / k;
      print_int (ans);
      putchar (i == n - 1 ? '\n' : ' ');
    }
    sum += t[i];
    cnt[t[i]]++;
  }
}

int main (void) {
  run ();
  return 0;
}