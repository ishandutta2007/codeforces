#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#include<inttypes.h>
#include<math.h>
#include<string.h>

typedef int32_t i32;
typedef int64_t i64;

const i32 mod1 = 1000050083;
const i32 mod2 = 1000050119;

typedef struct hash_node {
  i32 hash1;
  i32 hash2;
} hash_node;

void run (void) {
  const i32 m = 500000;
  char *t = (char *) calloc (m + 1, sizeof (char));
  char *s = (char *) calloc (m + 1, sizeof (char));
  scanf ("%s", t);
  scanf ("%s", s);
  i32 cntT[2] = {0, 0};
  i32 cntS[2] = {0, 0};
  for (i32 i = 0; t[i] != '\0'; ++i) {
    i32 k = t[i] - '0';
    cntT[k]++;
  }
  for (i32 i = 0; s[i] != '\0'; ++i) {
    i32 k = s[i] - '0';
    cntS[k]++;
  }
  if (!(cntT[0] >= cntS[0] && cntT[1] >= cntS[1])) {
    puts (t);
    return;
  }
  i32 len = strlen (s);
  hash_node *hash = (hash_node *) calloc (len + 1, sizeof (hash_node));
  i32 rad = 3;
  i32 *mpow1 = (i32 *) calloc (len + 1, sizeof (i32));
  i32 *mpow2 = (i32 *) calloc (len + 1, sizeof (i32));
  mpow1[0] = 1;
  mpow2[0] = 1;
  for (i32 i = 1; i <= len; ++i) {
    mpow1[i] = (i64) rad * mpow1[i - 1] % mod1;
    mpow2[i] = (i64) rad * mpow2[i - 1] % mod2;
  }
  for (i32 i = 1; i <= len; ++i) {
    hash[i].hash1 = ((i64)rad * hash[i - 1].hash1 + s[i - 1] - '0' + 1) % mod1;
    hash[i].hash2 = ((i64)rad * hash[i - 1].hash2 + s[i - 1] - '0' + 1) % mod2;
  }
  i32 k = 1;
  for (; k <= len; ++k) {
    if (hash[len - k].hash1 != (mod1 + hash[len].hash1 - (i64)hash[k].hash1 * mpow1[len - k] % mod1) % mod1) continue;
    if (hash[len - k].hash2 != (mod2 + hash[len].hash2 - (i64)hash[k].hash2 * mpow2[len - k] % mod2) % mod2) continue;
    break;
  }
  i32 p = 0;
  memcpy (t + p, s, sizeof (char) * len);
  p += len;
  cntT[0] -= cntS[0];
  cntT[1] -= cntS[1];
  cntS[0] = cntS[1] = 0;
  for (i32 i = 0; i < k; ++i) {
    i32 x = s[len - 1 - i] - '0';
    cntS[x]++;
  }
  while (cntT[0] >= cntS[0] && cntT[1] >= cntS[1]) {
    memcpy (t + p, s + len - k, sizeof (char) * k);
    cntT[0] -= cntS[0];
    cntT[1] -= cntS[1];
    p += k;
  }
  while (cntT[0]--) t[p++] = '0';
  while (cntT[1]--) t[p++] = '1';
  puts (t);
}

int main (void) {
  run ();
  return 0;
}