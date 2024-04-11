#include<bits/stdc++.h>

#define F first
#define S second
#define PB push_back
#define sz(s) (int(s.size()))
#define bit(n, k) (((n)>>(k))&1)

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;

const int maxn = 1e6 + 10;

int f[maxn];
int pr[maxn];

int main(){
    ios_base::sync_with_stdio(0), cin.tie(), cout.tie();

    for(int i = 2; i < maxn; i++){
	if(pr[i] == 0){
	    for(int j = i; j < maxn; j+= i)
		pr[j]= i;
	}
    }
    f[1] = 1;
    for(int i = 2; i < maxn; i++){
	int p = pr[i], cnt = 0, x = i;
	while(x % p == 0)
	    x/=p, cnt++;
	f[i] = f[x] * (cnt & 1 ? p : 1);
    }
    
    int q;
    cin >> q;
    while(q--){
	int n;
	cin >> n;
	map<int, int> mp;
	for(int i = 0; i < n; i++){
	    int x;
	    cin >> x;
	    mp[f[x]]++;
	}
	int ans0 = 0, ans1 = 0;
	for(auto it : mp){
	    ans0 = max(ans0, it.S);
	    if(it.F == 1 || (it.S&1) == 0)
		ans1+= it.S;
	}
	ans1 = max(ans1, ans0);
	int qq;
	cin >> qq;
	while(qq--){
	    ll x;
	    cin >> x;
	    if(x == 0)
		cout << ans0 << "\n";
	    else
		cout << ans1 << "\n";
	}
    }
    return 0;
}