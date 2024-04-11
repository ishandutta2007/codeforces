#include <bits/stdc++.h>

using namespace std;

#define out(x) cerr << #x"=" << x << endl

long double x, y, z;
double dx, dy, dz;
long double val[13];
char s[][20] = {"", "x^y^z", "x^z^y", "(x^y)^z", "(x^z)^y", 
  "y^x^z", "y^z^x", "(y^x)^z", "(y^z)^x",
  "z^x^y", "z^y^x", "(z^x)^y", "(z^y)^x"};

int main() {
  scanf("%lf%lf%lf", &dx, &dy, &dz);
  x = dx;
  y = dy;
  z = dz;
  val[1] = pow(y, z) * log(x);
  val[2] = pow(z, y) * log(x);
  val[3] = val[4] = y * z * log(x);
  val[5] = pow(x, z) * log(y);
  val[6] = pow(z, x) * log(y);
  val[7] = val[8] = x * z * log(y);
  val[9] = pow(x, y) * log(z);
  val[10] = pow(y, x) * log(z);
  val[11] = val[12] = x * y * log(z);
  int who = 0;
  for (int i = 1; i <= 12; ++i) {
    if (val[i] > val[who]) {
      who = i;
    }
  }
  if (who == 0) {
    val[1] = pow(x, pow(y, z));
    val[2] = pow(x, pow(z, y));
    val[3] = val[4] = pow(x, y * z);
    val[5] = pow(y, pow(x, z));
    val[6] = pow(y, pow(z, x));
    val[7] = val[8] = pow(y, x * z);
    val[9] = pow(z, pow(x, y));
    val[10] = pow(z, pow(y, x));
    val[11] = val[12] = pow(z, x * y);
    for (int i = 1; i <= 12; ++i) {
      if (val[i] > val[who]) {
        who = i;
      }
    }
    if (!who) who = 1;
  }
  puts(s[who]);
  return 0;
}