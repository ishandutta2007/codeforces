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

const string s = "fedabc";

ll n;
char c;
ll od;

int main() {
	cin >> n >> c;
	--n;

	od = n / 4 * 2;
	if (n % 2 == 1) ++od;
	od *= 6;

	rep(i, 6) if (s[i] == c) {
		od += i + 1;
	}

	od += n / 4 * 4 + (n % 4 >= 2 ? n % 4 - 2 : n % 4);

	cout << od << endl;

	return 0;
}