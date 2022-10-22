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
vi vec;

int main() {
    cin >> n;
    vec.pb(1);
    rep(i, n - 1) {
	vec.pb(1);
	int sz;

	while (true) {
	    sz = vec.size();
	    if (sz < 2 || vec[sz-1] != vec[sz-2]) break;
	    int num = vec[sz-1] + 1;
	    vec.pop_back(); vec.pop_back();
	    vec.pb(num);
	}
    }

    rep(i, vec.size()) cout << vec[i] << (i + 1 == (int)vec.size() ? '\n' : ' ');

    return 0;
}