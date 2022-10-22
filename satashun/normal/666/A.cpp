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

int l;
string s;
set<string> st;

set<string> dp[10010];

int main() {
    ios::sync_with_stdio(false);

    cin >> s;
    l = s.size();

    dp[l].insert("");

    for (int i = l; i > 5; --i) {
	for (const string u : dp[i]) {
	    if (i - 2 >= 5) {
		string t;
		t.pb(s[i - 2]);
		t.pb(s[i - 1]);
		if (t != u) {
		    st.insert(t);
		    dp[i - 2].insert(t);
		}
	    }

	    if (i - 3 >= 5) {
		string t;
		t.pb(s[i - 3]);
		t.pb(s[i - 2]);
		t.pb(s[i - 1]);
		if (t != u) {
		    st.insert(t);
		    dp[i - 3].insert(t);
		}		
	    }
	}
    }

    cout << st.size() << "\n";
    for (const string t : st) cout << t << "\n";

    return 0;
}