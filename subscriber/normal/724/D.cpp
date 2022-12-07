#include<bits/stdc++.h>
#define mp make_pair
#define pb push_back      
#define F first
#define S second
#define SS stringstream
#define sqr(x) ((x)*(x))
#define m0(x) memset(x,0,sizeof(x))
#define m1(x) memset(x,63,sizeof(x))
#define CC(x) cout << (x) << endl
#define pw(x) (1ll<<(x))
#define buli(x) __builtin_popcountll(x)
#define forn(i, n) for(int i = 0 ; (i) < (n) ; ++i)
#define M 1000000007
#define N 211111

#define TASK "1"

using namespace std;

int k, n;
string s;
int ty[N];

vector<int> v[33];
string ans = "";

int main(){
	#ifdef home
		freopen(TASK".in","r",stdin);	
		freopen(TASK".out","w",stdout);
	#endif		
	ios::sync_with_stdio(false);
	cin >> k;
	cin >> s;
	n = s.size();
	for (int i = 0; i < s.size(); i++) v[s[i] - 'a'].pb(i);

	for (int c = 0; c < 26; c++) {
		for (int i = 0; i < v[c].size(); i++) ty[v[c][i]] = 2;

		vector<int> e;

		for (int i = 0; i < n; i++) {
			if (ty[i] == 0) continue;
			while (e.size() > 0 && ty[e.back()] == 2) {
				int de = 0;
				if (e.size() == 1 && i < k) de = 1;
				if (e.size() > 1 && i - e[e.size() - 2] <= k) de = 1;
				if (de) e.pop_back(); else break; 
			}
			e.pb(i);
		}
		while (e.size() > 0 && ty[e.back()] == 2) {
			int de = 0;
			if (e.size() > 1 && n - 1 - e[e.size() - 2] < k) de = 1;
			if (de) e.pop_back(); else break; 
		}

//		for (int i = 0; i< e.size(); i++) cout << e[i] << " ";
//		cout << endl;

		int ok = 1;
		if (e.size() == 0) {
			ok = 0;
		} else if (e[0] >= k) ok = 0;
		else if (n - e.back() - 1 >= k) ok = 0; 
		else {
			for (int i = 1; i < e.size(); i++) if (e[i] - e[i - 1] > k) ok = 0;
		}
		if (ok) {
			for (int i = 0; i < e.size(); i++) if (ty[e[i]] == 2) ans.pb(c + 'a');
			break;
		} else {	
			for (int i = 0; i < v[c].size(); i++) {
				ans.pb(c + 'a');
				ty[v[c][i]] = 1;
			}
		}
	}
	cout << ans << endl;
	return 0;
}