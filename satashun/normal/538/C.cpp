#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
typedef long long ll;

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second
#define rep(i,n) rep2(i,0,n)
#define rep2(i,m,n) for(int i=m;i<(n);++i)
#define ALL(c) (c).begin(),(c).end()

int n, m, ma;
int d[100010], h[100010];

int main(){
    cin >> n >> m;
    rep(i, m) cin >> d[i] >> h[i];
    rep(i, m - 1){
	if(abs(h[i] - h[i+1]) > d[i+1] - d[i]){
	    puts("IMPOSSIBLE");
	    return 0;
	}
    }

    ma = max(h[0] + d[0] - 1, h[m - 1] + n - d[m - 1]);
    rep(i, m) ma = max(ma, h[i]);
    rep(i, m - 1){
	int lo = max(h[i], h[i+1]), hi = 1 << 30;
	while(hi - lo > 1){
	    int mid = (hi + lo) / 2;
	    if(mid - h[i] + mid - h[i + 1] <= d[i + 1] - d[i]) lo = mid;
	    else hi = mid;
	}
	ma = max(ma, lo);
    }
    cout << ma << endl;
    return 0;
}