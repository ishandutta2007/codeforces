// Never let them see you bleed...
// Shayan.P  2020-05-12

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

int pr[maxn];

vector<int> v[maxn];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie();

    for(int i = 2; i < maxn; i++){
	if(pr[i] == 0)
	    for(int j = i; j < maxn; j+=i)
		pr[j] = i;
    }
    
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
	int x;
	cin >> x;
	while(x > 1){
	    int p = pr[x], cnt = 0;
	    while(x % p == 0)
		x/=p, cnt++;
	    v[p].PB(cnt);
	}
    }
    ll ans = 1;
    for(int i = 1; i < maxn; i++){
	if(sz(v[i]) >= n-1){
	    if(sz(v[i]) == n-1)
		v[i].PB(0);
	    sort(v[i].begin(), v[i].end());
	    for(int j = 0; j < v[i][1]; j++)
		ans*= i;
	}
    }
    return cout << ans << endl, 0;
}