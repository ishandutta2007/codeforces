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
string s, ans;

int main() {
    cin >> s;
    n = s.size();
    ans = s;

    rep(i, n) {
	if (s[i] != 'a') {
	    int j = i;
	    while (j < n && s[j] != 'a') {
		--ans[j++];
	    }
	    cout << ans << endl;
	    return 0;
	}
    }

    ans.back() = 'z';
    cout << ans << endl;

    return 0;
}