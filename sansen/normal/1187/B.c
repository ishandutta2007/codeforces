#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#include<inttypes.h>

typedef int64_t i64;
typedef int32_t i32;

static void print_int(i64 n){if(n<0){putchar('-');n=-n;}if(n==0){putchar('0');return;}int s[20],len=0;while(n>0){s[len++]=n%10+'0';n/=10;}while(len>0){putchar(s[--len]);}}
static i64 read_int(void){int prev='\0';int c=getchar();while(!('0'<=c && c<='9')){prev=c;c=getchar();}i64 res=0;while('0'<=c && c<='9'){res=10*res+c-'0';c=getchar();}return prev=='-'?-res:res;}

#define ALLOC(size,type) ((type*)calloc((size),sizeof(type)))

#define POS(i, j) ((i) * f + (j))

void run (void) {
  i32 n = read_int();
  char *s = ALLOC (n + 1, char);
  scanf ("%s", s);
  const i32 f = 26;
  i32 *cnt = ALLOC (f * (n + 1), i32);
  for (i32 i = 0; i < n; ++i) {
    i32 k = s[i] - 'a';
    cnt[POS(i, k)] = 1;
  }
  for (i32 i = n - 1; i >= 0; --i) {
    for (i32 j = 0; j < f; ++j) {
      cnt[POS(i, j)] += cnt[POS(i + 1, j)];
    }
  }
  i32 m = read_int();
  char *t = ALLOC (200000 + 1, char);
  while (m--) {
    scanf ("%s", t);
    i32 c[26];
    for (i32 i = 0; i < f; ++i) {
      c[i] = 0;
    }
    for (i32 i = 0; t[i] != '\0'; ++i) {
      c[t[i] - 'a']++;
    }
    i32 l = 0;
    i32 r = n;
    while (r - l > 1) {
      i32 mid = (l + r) / 2;
      i32 ok = 1;
      for (i32 i = 0; i < f; ++i) {
        if (cnt[POS(0, i)] - cnt[POS(mid, i)] < c[i]) {
          ok = 0;
        }
      }
      if (ok) {
        r = mid;
      } else {
        l = mid;
      }
    }
    print_int (r);
    puts ("");
  }
}

int main (void) {
  run ();
  return 0;
}