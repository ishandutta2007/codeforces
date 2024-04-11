#include<bits/stdc++.h>

#define F first
#define S second
#define PB push_back
#define sz(s) (int(s.size()))
#define bit(n, k) (((n)>>(k))&1)

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;

const int maxn = 1e5 + 10;

int cnt[maxn];

int main(){
    ios_base::sync_with_stdio(0), cin.tie(), cout.tie();

    int q;
    cin >> q;
    while(q--){
	int n, p, k;
	cin >> n >> p >> k;
	string s;
	cin >> s;
	int x, y;
	cin >> x >> y;
	for(int i = n-1; i >= 0; i--){
	    cnt[i] = (i + k >= n ? 0 : cnt[i+k]) + (s[i] == '0');	    
	}
	int ans = n * x;
	--p;
	for(int i = p; i < n; i++){
	    ans = min(ans, (i-p) * y + cnt[i] * x);
	}
	cout << ans << "\n";
    }
    return 0;
}