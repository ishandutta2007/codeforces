// Never let them see you bleed...
// Shayan.P  2020-06-11

#include<bits/stdc++.h>

#define F first
#define S second
#define PB push_back
#define sz(s) int((s).size())
#define bit(n,k) (((n)>>(k))&1)

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

const int maxn = 33, mod = 1e9 + 7, inf = 1e9 + 10;

int cnt[maxn][2];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie();

    int q;
    cin >> q;

    while(q--){
	int n, m;
	cin >> n >> m;
	memset(cnt, 0, sizeof cnt);
	for(int i = 0; i < n; i++){
	    for(int j = 0; j < m; j++){
		bool x;
		cin >> x;
		cnt[min(i+j, n+m-2-i-j)][x]++;
	    }
	}
	int ans = 0;
	for(int i = 0; i < maxn; i++){
	    if(2 * i != n+m-2)
		ans+= min(cnt[i][0], cnt[i][1]);
	}
	cout << ans << "\n";
    }
    return 0;
}