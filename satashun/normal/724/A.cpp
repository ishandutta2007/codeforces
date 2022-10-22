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

const int mon[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
const string day[7] = {"monday", "tuesday", "wednesday", "thursday", "friday", "saturday", "sunday"};

int main() {
	string a, b;
	cin >> a >> b;

	int p1;
	rep(i, 7) {
		if (day[i] == a) {
			p1 = i;
			break;
		}
	}

	int w;

	rep(t, 7) {
		int u = (p1 + t) % 7;
		if (day[u] == b) {
			w = t;
			break;
		}
	}

	rep(i, 12) {
		if (mon[i] % 7 == w) {
			puts("YES");
			return 0;
		}
	}

	puts("NO");

	return 0;
}