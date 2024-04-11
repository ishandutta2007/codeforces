#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#include<inttypes.h>

typedef int64_t i64;
typedef int32_t i32;

static i64 read_int(void){int prev='\0';int c=getchar();while(!('0'<=c && c<='9')){prev=c;c=getchar();}i64 res=0;while('0'<=c && c<='9'){res=10*res+c-'0';c=getchar();}return prev=='-'?-res:res;}

#define ALLOC(size,type) ((type*)calloc((size),sizeof(type)))

#define POS(i, j) ((i) * w + (j))

void run (void) {
  i32 h = read_int();
  i32 w = read_int();
  char *s = ALLOC (h * w + 1, char);
  for (i32 i = 0; i < h; ++i) {
    scanf ("%s", s + i * w);
  }
  i32 cnt = 0;
  for (i32 i = 0; i < h * w; ++i) {
    cnt += s[i] == '*' ? 1 : 0;
  }
  for (i32 i = 1; i < h; ++i) {
    for (i32 j = 1; j < w; ++j) {
      if (s[POS(i, j)] != '*') continue;
      i32 d[4] = {1, 0, -1, 0};
      i32 ok = 1;
      for (i32 k = 0; k < 4; ++k) {
        if (s[POS(i + d[k], j + d[k ^ 1])] != '*') {
          ok = 0;
        }
      }
      if (!ok) continue;
      i32 c = 1;
      for (i32 k = 0; k < 4; ++k) {
        for (i32 x = i + d[k], y = j + d[k ^ 1]; 0 <= x && x < h && 0 <= y && y < w && s[POS(x, y)] == '*'; x += d[k], y += d[k ^ 1]) {
          c++;
        }
      }
      if (c == cnt) {
        puts ("YES");
        return;
      }
    }
  }
  puts ("NO");
}

int main (void) {
  run ();
  return 0;
}