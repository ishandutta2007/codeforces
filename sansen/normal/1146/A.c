#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#include<inttypes.h>
#include<string.h>

typedef int64_t i64;
typedef int32_t i32;

static void print_int(i64 n){if(n<0){putchar('-');n=-n;}if(n==0){putchar('0');return;}int s[20],len=0;while(n>0){s[len++]=n%10+'0';n/=10;}while(len>0){putchar(s[--len]);}}

#define MIN(a,b) ((a)<(b)?(a):(b))

void run (void) {
  char *s = (char *) calloc (50 + 1, sizeof (char));
  scanf ("%s", s);
  i32 n = strlen (s);
  i32 c = 0;
  for (i32 i = 0; i < n; ++i) {
    if (s[i] == 'a') {
      c++;
    }
  }
  print_int (MIN(n, 2 * c - 1));
  puts("");
}

int main (void) {
  run ();
  return 0;
}