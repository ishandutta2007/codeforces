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
#define N 611111

#define TASK "1"

using namespace std;

char ans[N];

int main(){
	#ifdef home
		freopen(TASK".in","r",stdin);	
		freopen(TASK".out","w",stdout);
	#endif		
	ios::sync_with_stdio(false);
	string s;
	cin >> s;
	multiset<char> A, B;
	for (int i = 0; i <s.size(); i++) A.insert(s[i]);
	cin >> s;
	for (int i = 0; i <s.size(); i++) B.insert(s[i]);

	int n = s.size();

	int t = 0;
	for (int i = 0; i < n; i++) {
		auto it = A.begin();
		int mina = (*it);
		it = B.end();
		it--;
		int maxb = (*it);
		if (mina < maxb) {
			if (t == 0) {
				it = A.begin();
				ans[i] = (*it);
				A.erase(it);
			} else {
				it = B.end();
				it--;
				ans[i] = (*it);
				B.erase(it);
			}
		} else {
			int needa = (n - i) / 2;
			int needb = (n - i) / 2;
			if ((n - i) % 2) {
				if (t == 0) needa++; else needb++;
			}
			vector<char> ga, gb;
			for (auto it = A.begin(); it != A.end(); it++) {
				if (needa == 0) break;
				needa--;
				ga.pb(*it);
			}
			auto it = B.end();
			while (needb > 0) {
				it--;
				needb--;
				gb.pb(*it);
			}
			reverse(ga.begin(), ga.end());
			reverse(gb.begin(), gb.end());
			for (int i = 0; i < ga.size(); i++) ans[n - 1 - i * 2 - t] = ga[i];
			for (int i = 0; i < gb.size(); i++) ans[n - 1 - i * 2 - (1 - t)] = gb[i];
			break;

		}
		t ^= 1;
	}
	puts(ans);
	return 0;
}