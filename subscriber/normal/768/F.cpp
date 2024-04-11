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

int fa[1000111], inv[1000111];

int pv(int a, int b) {
	if (b == 0) return 1;
	long long r = pv(a, b / 2);
	r = r * r % M;
	if (b % 2) r = r * a % M;
	return r;
}

int C(int a, int b) {
	return fa[a] * 1ll * inv[a - b] % M * inv[b] % M;
}

int split(int pl, long long it) {
	if (it < pl) return 0;
	it -= pl;
	return C(it + pl - 1, pl - 1);
}

int main(){
	#ifdef home
		freopen(TASK".in","r",stdin);	
		freopen(TASK".out","w",stdout);
	#endif		
	ios::sync_with_stdio(false);
	int f, w, h;

	cin >> f >> w >> h;

	if (w == 0) {
		cout << 1 << endl;
		return 0;
	}
	if (f == 0) {
		if (w > h) cout << 1 << endl; else cout << 0 << endl;
		return 0;
	}

	fa[0] = 1;
	for (int i = 1; i <= (f + w) * 3; i++) fa[i] = fa[i - 1] * 1ll * i % M;
	for (int i = 0; i <= (f + w) * 3; i++) inv[i] = pv(fa[i], M - 2);

	int all = 0;
	int good = 0;

	for (int l = 1; l <= f + w; l++) for (int fi = 0; fi < 2; fi++) {
		int F = l / 2;
		int W = l / 2;
		if (l % 2) {
			if (fi) F++; else W++;
		}

		if (F > f) continue;
		if (W > w) continue;

		int mu = split(F, f);


		int al = split(W, w);

		int mg = split(W, w - W * 1ll * h);

//		cout << l << " " << fi << " " << mu << " " <<  al << endl;

		all = (all + mu * 1ll * al) % M;
		good = (good + mu * 1ll * mg) % M;
	}
//	cout << good << endl;
//	cout << all << endl;

	cout << good * 1ll * pv(all, M - 2) % M << endl;
	return 0;
}