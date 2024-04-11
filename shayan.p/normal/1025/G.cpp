// And you curse yourself for things you never done

#include<bits/stdc++.h>

#define F first
#define S second
#define PB push_back
#define sz(s) int((s).size())
#define bit(n,k) (((n)>>(k))&1)

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

const int maxn = 510, mod = 1e9 + 7, inf = 1e9 + 10;

int tw[maxn], cnt[maxn];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie();

    tw[0] = 1;
    for(int i = 1; i < maxn; i++)
	tw[i] = 2ll * tw[i-1] % mod;
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
	int x;
	cin >> x;
	if(x != -1)
	    cnt[x]++;
    }
    int ans = tw[n-1]-1;
    for(int i = 1; i <= n; i++){
	ans = (ans - tw[cnt[i]] + 1 + mod) % mod;
    }
    return cout << ans << endl, 0;
}