#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#include<inttypes.h>

typedef int64_t i64;
typedef int32_t i32;

static void print_int(i64 n){if(n<0){putchar('-');n=-n;}if(n==0){putchar('0');return;}int s[20],len=0;while(n>0){s[len++]=n%10+'0';n/=10;}while(len>0){putchar(s[--len]);}}
static i64 read_int(void){int prev='\0';int c=getchar();while(!('0'<=c && c<='9')){prev=c;c=getchar();}i64 res=0;while('0'<=c && c<='9'){res=10*res+c-'0';c=getchar();}return prev=='-'?-res:res;}

#define MIN(a,b) ((a)<(b)?(a):(b))

void run (void) {
  i32 t = read_int ();
  char *s = (char *) calloc (100 + 1, sizeof (char));
  while (t--) {
    i32 n = read_int ();
    scanf ("%s", s);
    if (s[0] == '>' || s[n - 1] == '<') {
      puts("0");
      continue;
    }
    i32 l;
    for (l = 0; s[l] != '>'; ++l);
    i32 r;
    for (r = 0; s[n - 1 - r] != '<'; ++r);
    print_int(MIN(l,r));
    puts("");
  }
}

int main (void) {
  run ();
  return 0;
}