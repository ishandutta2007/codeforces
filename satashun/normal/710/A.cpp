#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
typedef vector<int> vi;

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second
#define rep(i,n) rep2(i,0,n)
#define rep2(i,m,n) for(int i=m;i<(n);i++)
#define ALL(c) (c).begin(),(c).end()

string s;
int a, b;
int ret;

int main() {
    cin >> s;
    a = s[0] - 'a';
    b = s[1] - '1';

    for (int i = a - 1; i <= a + 1; ++i) {
	for (int j = b - 1; j <= b + 1; ++j) {
	    if (i == a && j == b) continue;
	    if (i >= 0 && i < 8 && j >= 0 && j < 8) ++ret;
	}
    }

    cout << ret << endl;

    return 0;
}