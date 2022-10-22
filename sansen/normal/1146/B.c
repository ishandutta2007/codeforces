#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#include<inttypes.h>
#include<string.h>

typedef int32_t i32;

void cond (int c) {
  if (!c) {
    puts(":(");
    exit (0);
  }
}

void run (void) {
  const i32 m = 100000;
  char *t = (char *) calloc (m + 1, sizeof (char));
  scanf ("%s", t);
  const i32 n = strlen (t);
  char *a = (char *) calloc (m + 1, sizeof (char));
  i32 len = 0;
  for (i32 i = 0; i < n; ++i) {
    if (t[i] == 'a') continue;
    a[len++] = t[i];
  }
  cond (len % 2 == 0);
  for (i32 i = 0; i < len / 2; ++i) {
    cond (a[i] == a[i + len / 2]);
  }
  i32 j = len / 2 - 1;
  i32 i = n - 1;
  for (; j >= 0; --i, --j) {
    cond (t[i] == a[j]);
  }
  t[i + 1] = '\0';
  puts(t);
}

int main (void) {
  run ();
  return 0;
}