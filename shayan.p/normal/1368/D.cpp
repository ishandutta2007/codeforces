// Never let them see you bleed...
// Shayan.P  2020-06-18

#include<bits/stdc++.h>

#define F first
#define S second
#define PB push_back
#define sz(s) int((s).size())
#define bit(n,k) (((n)>>(k))&1)

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

const int maxn = 2e5 + 10, mod = 1e9 + 7, inf = 1e9 + 10;

int cnt[22];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie();

    int n;
    cin >> n;
    
    for(int i = 0; i < n; i++){
	int x;
	cin >> x;
	for(int j = 0; j < 22; j++)
	    cnt[j]+= bit(x, j);
    }
    ll ans = 0;
    for(int i = 0; i < n; i++){
	int x = 0;
	for(int j = 0; j < 22; j++){
	    if(cnt[j])
		cnt[j]--, x+= 1<<j;
	}
	ans+= 1ll * x * x;
    }
    return cout << ans << endl, 0;
}