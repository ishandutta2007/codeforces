#include<stdio.h>
#include<stdint.h>
#include<inttypes.h>

typedef int64_t i64;
typedef int32_t i32;

static void print_int(i64 n){if(n<0){putchar('-');n=-n;}if(n==0){putchar('0');return;}int s[20],len=0;while(n>0){s[len++]=n%10+'0';n/=10;}while(len>0){putchar(s[--len]);}}
static i64 read_int(void){int prev='\0';int c=getchar();while(!('0'<=c && c<='9')){prev=c;c=getchar();}i64 res=0;while('0'<=c && c<='9'){res=10*res+c-'0';c=getchar();}return prev=='-'?-res:res;}

void run (void) {
  i32 n = read_int();
  i32 a[100];
  for (i32 i = 0; i < n; ++i) {
    a[i] = read_int();
  }
  i32 cnt = 0;
  const i32 inf = n * 5;
  for (i32 i = 1; i < n; ++i) {
    if (a[i] == 1 && a[i - 1] == 2) {
      cnt += 3;
    } else if (a[i] == 1 && a[i - 1] == 3) {
      cnt += 4;
    } else if (a[i] == 2 && a[i - 1] == 1) {
      cnt += 3;
      if (i > 1 && a[i - 2] == 3) cnt--;
    } else if (a[i] == 2 && a[i - 1] == 3) {
      cnt += inf;
      break;
    } else if (a[i] == 3 && a[i - 1] == 1) {
      cnt += 4;
    } else if (a[i] == 3 && a[i - 1] == 2) {
      cnt += inf;
      break;
    }
  }
  if (cnt >= inf) {
    puts ("Infinite");
  } else {
    puts ("Finite");
    print_int (cnt);
    puts ("");
  }
}

int main (void) {
  run ();
  return 0;
}