#include <bits/stdc++.h>

#define ff first
#define ss second
#define pb push_back
#define sqr(x) ((x) * (x))
#define rep(a,b,c) for(int a=b;a<c;++a)
#define per(a,b,c) for(int a=b;a>c;--a)

using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 1e6+300;

int cnt[MAXN];

int main() {
    ios_base::sync_with_stdio(0);
    srand(time(NULL));
    cout << fixed;
    cout.precision(10);
    cerr << fixed;
    cerr.precision(10);
    
    int n;
    cin >> n;

    rep(i,0,MAXN-1) cnt[i] = 0;

    rep(i,0,n) {
    	int a;
    	cin >> a;
    	++cnt[a];
    }

    int ans = 0;

    rep(i,0,MAXN-1) {
		cnt[i + 1] += cnt[i] / 2;
		cnt[i] %= 2;
		ans += cnt[i];
    }

    ans += cnt[MAXN];

    cout << ans<< '\n';
       

    return 0;
}