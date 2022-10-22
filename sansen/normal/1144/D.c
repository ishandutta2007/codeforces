#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#include<inttypes.h>

typedef int64_t i64;
typedef int32_t i32;

static void print_int(i64 n){if(n<0){putchar('-');n=-n;}if(n==0){putchar('0');return;}int s[20],len=0;while(n>0){s[len++]=n%10+'0';n/=10;}while(len>0){putchar(s[--len]);}}
static i64 read_int(void){int prev='\0';int c=getchar();while(!('0'<=c && c<='9')){prev=c;c=getchar();}i64 res=0;while('0'<=c && c<='9'){res=10*res+c-'0';c=getchar();}return prev=='-'?-res:res;}

void operation (i32 t, i32 i, i32 j) {
  print_int (t);
  putchar (' ');
  print_int (i);
  putchar (' ');
  print_int (j);
  putchar ('\n');
}

void run (void) {
  i32 n = read_int();
  i32 *a = (i32 *) calloc (n, sizeof (i32));
  i32 *cnt = (i32 *) calloc (200000 + 1, sizeof (i32));
  for (i32 i = 0; i < n; ++i) {
    a[i] = read_int();
    cnt[a[i]]++;
  }
  i32 max = a[0];
  for (i32 i = 0; i <= 200000; ++i) {
    if (cnt[max] < cnt[i]) {
      max = i;
    }
  }
  print_int (n - cnt[max]);
  puts("");
  i32 k;
  for (k = 0; a[k] != max; ++k);
  for (i32 i = k - 1; i >= 0; --i) {
    if (a[i] == max) continue;
    if (a[i] < max) {
      operation (1, i + 1, i + 2);
    } else {
      operation (2, i + 1, i + 2);
    }
  }
  for (i32 i = k + 1; i < n; ++i) {
    if (a[i] == max) continue;
    if (a[i] < max) {
      operation (1, i + 1, i);
    } else {
      operation (2, i + 1, i);
    }
  }
}

int main (void) {
  run ();
  return 0;
}