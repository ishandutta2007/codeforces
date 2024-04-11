#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#include<inttypes.h>

typedef int64_t i64;
typedef int32_t i32;

static void print_int(i64 n){if(n<0){putchar('-');n=-n;}if(n==0){putchar('0');return;}int s[20],len=0;while(n>0){s[len++]=n%10+'0';n/=10;}while(len>0){putchar(s[--len]);}}
static i64 read_int(void){int prev='\0';int c=getchar();while(!('0'<=c && c<='9')){prev=c;c=getchar();}i64 res=0;while('0'<=c && c<='9'){res=10*res+c-'0';c=getchar();}return prev=='-'?-res:res;}

const i32 mod = 1000000007;

i32 mod_pow (i32 r, i64 n) {
  i64 t = 1;
  i64 s = r;
  while (n > 0) {
    if (n & 1) t = t * s % mod;
    s = s * s % mod;
    n >>= 1;
  }
  return t;
}

i32 inv (i32 a) {
  return mod_pow (a, mod - 2);
}

#define SIZE 3

const i32 size = SIZE;

void matmul (i32 *c, i32 *a, i32 *b) {
  i64 tmp[SIZE * SIZE];
  for (i32 i = 0; i < size; ++i) {
    for (i32 j = 0; j < size; ++j) {
      tmp[i * size + j] = 0;
      for (i32 k = 0; k < size; ++k) {
        tmp[i * size + j] += (i64) a[i * size + k] * b[k * size + j];
      }
    }
  }
  for (i32 i = 0; i < size * size; ++i) {
    c[i] = tmp[i] % (mod - 1);
  }
}

//f_x = c^{2x - 6} * f_{x - 1} * f_{x - 2} * f_{x - 3}
//g_x = log f_x
//d = log c
//g_x = g_{x - 1} + g_{x - 2} + g_{x - 3} + (2x - 6) d
//h_x = g_x + xd
//h_x = h_{x - 1} + h_{x - 2} + h_{x - 3}
void run (void) {
  i64 n = read_int();
  i32 f[SIZE];
  for (i32 i = 0; i < size; ++i) {
    f[i] = read_int();
  }
  i32 c = read_int();
  i32 t[SIZE * SIZE] = {1,0,0,
                        0,1,0,
                        0,0,1};
  i32 s[SIZE * SIZE] = {0,1,0,
                        0,0,1,
                        1,1,1};
  i64 x = n;
  n--;
  while (n > 0) {
    if (n & 1) matmul (t, s, t);
    matmul (s, s, s);
    n >>= 1;
  }
  i64 ans = mod_pow (inv (c), x);
  for (i32 i = 0; i < 3; ++i) {
    ans = ans * mod_pow (f[i], t[i]) % mod * mod_pow (c, (i64) (i + 1) * t[i]) % mod;
  }
  print_int (ans);
  puts ("");
}

int main (void) {
  run ();
  return 0;
}