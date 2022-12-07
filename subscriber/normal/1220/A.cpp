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
#define N 411111

#define TASK "1"

using namespace std;

int main(){
	#ifdef home
		freopen(TASK".in","r",stdin);	
		freopen(TASK".out","w",stdout);
	#endif		
	ios::sync_with_stdio(false);
	int n;
	string s;
	cin >> n >> s;
	int cn = 0;
	for (int i = 0; i < n; i++) if (s[i] == 'n') cn++;

	int zn = (n - cn * 3) / 4;
		for (int i = 0; i < cn; i++) cout << 1 << " ";
		for (int i = 0; i < zn; i++) cout << 0 << " ";
	return 0;
}