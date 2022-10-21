#include <bits/stdc++.h>
using namespace std;

char readchar() {
  static char buf[1 << 15], *ptr = buf, *end = buf;
  if (ptr == end) ptr = buf, end = buf + fread(buf, 1, 1 << 15, stdin);
  return *ptr++;
}
void writechar(char c = 0) {
  static char buf[1 << 15], *ptr = buf;
  if (ptr == end(buf) or c == 0) fwrite(buf, 1, ptr - buf, stdout), ptr = buf;
  *ptr++ = c;
}
template <class Z = int> Z getint() {
  char c = readchar();
  bool neg = c == '-';
  Z res = neg ? 0 : c - '0';
  while (isdigit(c = readchar())) res = res * 10 + (c - '0');
  return neg ? -res : res;
}
template <class Z> void putint(Z a, char delim = '\n') {
  if (a < 0) writechar('-'), a = -a;
  int d[40], i = 0;
  do d[i++] = a % 10; while (a /= 10);
  while (i--) writechar('0' + d[i]);
  writechar(delim);
}

constexpr int lim = 1e6;

int main() {
  int x = getint(), n = getint();
  bool lt = false, gt = false;
  set<int> se;
  while (n--) {
    int a = getint();
    if (a == x) {
      putint(1);
      writechar();
      exit(0);
    }
    se.insert(a);
    if (a < x) {
      lt = true;
    } else {
      gt = true;
    }
  }
  if (not lt or not gt) {
    putint(-1);
    writechar();
    exit(0);
  }
  bitset<lim + 1> bs, nbs;
  bs[0] = 1;
  for (int k = 0; ; ++k) {
    if (k and bs[k * x]) {
      putint(k);
      break;
    }
    nbs.reset();
    for (int e : se) {
      nbs |= bs << e;
    }
    swap(bs, nbs);
  }
  writechar();
}