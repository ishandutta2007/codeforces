// Never let them see you bleed...
// Shayan.P  2020-06-16

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
	int n, x, sm = 0;
	int fr = -1, ls = -1;
	cin >> n >> x;
	for(int i = 0; i < n; i++){
	    cin >> a[i];
	    a[i]%= x;
	    sm = (sm + a[i]) % x;
	    if(a[i] != 0){
		ls = i;
		if(fr == -1)
		    fr = i;
	    }		
	}
	int ans = n;
	if(sm == 0){
	    if(fr == -1)
		ans = -1;
	    else
		ans = max(n - fr - 1, ls);
	}
	cout << ans << "\n";	    
    }
    return 0;
}