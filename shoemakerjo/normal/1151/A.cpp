#include <bits/stdc++.h>

using namespace std;

int n;
string s;
string g = "ACTG";

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
  cin >> n >> s;
  int res = 100000;

  for (int i = 0; i <= n-4; i++) {
    int cval = 0;
    for (int j = 0; j < 4; j++) {
      int mval = s[i+j]-'A';
      int cg = g[j]-'A';

      int cadd = abs(cg - mval);
      cadd = min(cadd, cg + 26 - mval);
      cadd = min(cadd, mval + 26 - cg);
      cval += cadd;
    }
    res = min(res, cval);

  }
  cout << res << endl;
}