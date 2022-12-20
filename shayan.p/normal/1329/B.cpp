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

int solve(ll n, int m){
    int ans = 1;    
    for(ll i = 1; i <= n; i*=2){
	ans = 1ll * ans * (( min(n, 2*i-1) - i + 2 ) % m) % m;
    }
    ans--;
    if(ans < 0)
	ans+= m;
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie();

    int q;
    cin >> q;
    while(q--){
	int n, m;
	cin >> n >> m;
	cout << solve(n, m) << "\n";
    }
    return 0;
}