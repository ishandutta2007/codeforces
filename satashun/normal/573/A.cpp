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

int n;
set<int> s;

int main() {
    cin >> n;

    rep(i, n) {
	int x;
	cin >> x;

	while (x % 2 == 0) x /= 2;
	while (x % 3 == 0) x /= 3;
	s.insert(x);
    }

    puts(s.size() == 1 ? "Yes" : "No");

    return 0;
}