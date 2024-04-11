#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#include<inttypes.h>

typedef int64_t i64;
typedef int32_t i32;

static i64 read_int(void){int prev='\0';int c=getchar();while(!('0'<=c && c<='9')){prev=c;c=getchar();}i64 res=0;while('0'<=c && c<='9'){res=10*res+c-'0';c=getchar();}return prev=='-'?-res:res;}

void run (void) {
  i32 n = read_int();
  char *s =(char *) calloc (n + 1, sizeof (char));
  scanf ("%s", s);
  if (n % 2 != 0) {
    puts (":(");
    return;
  }
  i32 cnt[2] = {0, 0};
  for (i32 i = 0; i < n; ++i) {
    if (s[i] == '?') continue;
    if (s[i] == '(') {
      cnt[0]++;
    } else {
      cnt[1]++;
    }
  }
  if (cnt[0] > n / 2 || cnt[1] > n / 2) {
    puts (":(");
    return;
  }
  for (i32 i = 0; i < n; ++i) {
    if (s[i] != '?') continue;
    if (cnt[0] < n / 2) {
      s[i] = '(';
      cnt[0]++;
    } else {
      s[i] = ')';
    }
  }
  for (i32 i = 0, k = 0; i < n; ++i) {
    k += (s[i] == '(' ? 1 : -1);
    if (i != n - 1 && k <= 0) {
      puts (":(");
      return;
    }
  }
  puts (s);
}

int main (void) {
  run ();
  return 0;
}