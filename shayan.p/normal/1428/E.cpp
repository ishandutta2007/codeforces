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

int a[maxn], cnt[maxn];

ll f(int n, int k){
    int c1 = n%k, c0 = k-c1;
    int x = n/k;
    return 1ll * x * x * c0 + 1ll * (x + 1) * (x + 1) * c1;
}
ll g(int pos){
    return f(a[pos], cnt[pos]) - f(a[pos], cnt[pos]+1);
}

int main(){
    ios_base::sync_with_stdio(0), cin.tie(), cout.tie();
    
    int n, k;
    cin >> n >> k;
    set<pair<ll, int>> st;
    k-= n;
    for(int i = 0; i < n; i++){
	cin >> a[i];
	cnt[i] = 1;
	if(a[i] > 1)
	    st.insert({g(i), i});
    }
    while(sz(st) && k){
	int id = st.rbegin()->S;
	st.erase({g(id), id});
	cnt[id]++;
	if(cnt[id] < a[id])
	    st.insert({g(id), id});
	k--;
    }
    ll ans = 0;
    for(int i = 0; i < n; i++){
	ans+= f(a[i], cnt[i]);
    }
    return cout << ans << endl, 0;
}