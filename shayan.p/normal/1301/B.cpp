// I think of what the world could be, A vision of the one I see, A million dreams is all it's gonna take

#include<bits/stdc++.h>

#define F first
#define S second
#define PB push_back
#define sz(s) int((s).size())
#define bit(n,k) (((n)>>(k))&1)

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

const int maxn = 1e5 + 10, mod = 1e9 + 7, inf = 1e9 + 10;

int a[maxn];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie();

    int q;
    cin >> q;
    while(q--){
	int n;
	cin >> n;
	for(int i = 0; i < n; i++)
	    cin >> a[i];
	int ans = 0, mx = -inf, mn = inf;
	for(int i = 0; i < n-1; i++){
	    if(a[i] != -1 && a[i+1] != -1)
		ans = max(ans, abs(a[i] - a[i+1]));
	    else if(a[i] != -1)
		mx = max(mx, a[i]), mn = min(mn, a[i]);
	    else if(a[i+1] != -1)
		mx = max(mx, a[i+1]), mn = min(mn, a[i+1]);	    
	}
	if(mx < mn)
	    cout << ans << " " << 1 << "\n";
	else
	    cout << max(ans, (mx - mn + 1) /2) << " " << (mx + mn)/2 << "\n";
    }
    return 0;
}