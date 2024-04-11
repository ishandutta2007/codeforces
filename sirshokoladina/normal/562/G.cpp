#include <bits/stdc++.h>

using namespace std;

#define forn(i,n) for (int i = 0; i < int(n); ++i)
#define ford(i,n) for (int i = int(n) - 1; i >= 0; ++i)
#define all(a) a.begin(), a.end()
#define sz(a) int(a.size())
#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define ve vector
#define pa pair

typedef long double ld;
typedef long long ll;
typedef unsigned char uc;
typedef unsigned int ui;
typedef unsigned long long ull;
typedef ve<int> vi;
typedef pa<int, int> pii;
typedef pa<int, ll> pil;
typedef pa<ll, int> pli;
typedef pa<ll, ll> pll;

template<typename A, typename B> bool umx (A &a, B b) {if (a < b) {a = b; return 1;} return 0;}
template<typename A, typename B> bool umn (A &a, B b) {if (b < a) {a = b; return 1;} return 0;}

const int size = 1000 * 1000 + 1000;

int degs[size];
int a[size], b[size], c[size];
set <int> mycur[size];
set <pair <int, int> > degsmx;
int n;
vector <int> ans;

int main () {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	scanf("%d", &n);
	for (int i = 0; i < 4 * n; i++) {
		scanf("%d%d%d", &a[i], &b[i], &c[i]);
		
		a[i]--, b[i]--, c[i]--;
		mycur[b[i]].insert(i);
		mycur[c[i]].insert(i);
	}
	
	for (int i = 0; i < n; i++)
		degs[i] = 8;
	for (int i = 0; i < n; i++) {
		degsmx.insert(mp(degs[i], i));
	}
	
	while (!degsmx.empty()) {
		int v = degsmx.rbegin()->sc;
//		degsmx.erase(*degsmx.rbegin());
		
		if (mycur[v].empty()) {
			degsmx.erase(*degsmx.rbegin());
			continue;
		} else {
			int any = *mycur[v].begin();
			ans.pb(any);
			
			mycur[b[any]].erase(any);
			degsmx.erase(mp(degs[b[any]], b[any]));
			degs[b[any]]--;
			degsmx.insert(mp(degs[b[any]], b[any]));
			
			
			mycur[c[any]].erase(any);
			degsmx.erase(mp(degs[c[any]], c[any]));
			degs[c[any]]--;
			degsmx.insert(mp(degs[c[any]], c[any]));
			
			degsmx.erase(mp(degs[a[any]], a[any]));
			degs[a[any]]++;
			degsmx.insert(mp(degs[a[any]], a[any]));
		}
	}
	
	reverse(ans.begin(), ans.end());
	printf("YES\n");
	for (int i = 0; i < (int) ans.size(); i++) {
		printf("%d ", ans[i] + 1);
	}
	printf("\n");
	
	return 0;
}