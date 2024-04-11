#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#include<string.h>

typedef int64_t i64;
typedef int32_t i32;

static i64 read_int(void){int prev='\0';int c=getchar();while(!('0'<=c && c<='9')){prev=c;c=getchar();}i64 res=0;while('0'<=c && c<='9'){res=10*res+c-'0';c=getchar();}return prev=='-'?-res:res;}

#define ALLOC(size,type) ((type*)calloc((size),sizeof(type)))

void run (void) {
  i32 n = read_int();
  const i32 m = 1000000;
  char *s = ALLOC (m + 1, char);
  char *t = ALLOC (m + 1, char);
  while (n--) {
    scanf ("%s", s);
    scanf ("%s", t);
    i32 slen = strlen (s);
    i32 tlen = strlen (t);
    i32 ok = 1;
    i32 j = 0;
    for (i32 i = 0; i < slen;) {
      char c = s[i];
      i32 cnt = 0;
      while (i < slen && s[i] == c) {
        cnt++;
        i++;
      }
      while (j < tlen && t[j] == c) {
        cnt--;
        j++;
      }
      if (cnt > 0) {
        ok = 0;
        break;
      }
    }
    if (j < tlen) ok = 0;
    puts (ok ? "YES" : "NO");
  }
}

int main (void) {
  run ();
  return 0;
}