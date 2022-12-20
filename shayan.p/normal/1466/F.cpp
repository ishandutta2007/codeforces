#include<bits/stdc++.h>

#define F first
#define S second
#define PB push_back
#define sz(s) (int(s.size()))
#define bit(n, k) (((n)>>(k))&1)

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;

const int maxn = 5e5 + 10, mod = 1e9 + 7;

int par[maxn], cnt[maxn], pw[maxn];

int fnd(int u){
    return par[u] < 0 ? u : par[u] = fnd(par[u]);
}
bool mrg(int a, int b){
    if( (a = fnd(a)) == (b = fnd(b)) )
	return 0;
    if(cnt[a] + cnt[b] > 1)
	return 0;
    if(par[a] > par[b])
	swap(a, b);
    par[a]+= par[b];
    par[b] = a;
    cnt[a]+= cnt[b];
    return 1;
}

int main(){
    ios_base::sync_with_stdio(0), cin.tie(), cout.tie();

    memset(par, -1, sizeof par);
    pw[0] = 1;
    for(int i = 1; i < maxn; i++)
	pw[i] = 2ll * pw[i-1] %mod;
    
    int q, n;
    cin >> q >> n;
    vector<int> ans;
    for(int i = 0; i < q; i++){
	int k;
	cin >> k;
	if(k == 1){
	    int a;
	    cin >> a;
	    if(cnt[fnd(a)] == 0)
		ans.PB(i), cnt[fnd(a)]++;
	}
	else{
	    int a, b;
	    cin >> a >> b;
	    if(mrg(a, b))
		ans.PB(i);
	}
    }
    cout << pw[sz(ans)] << " " << sz(ans) << "\n";
    for(int x : ans)
	cout << x + 1 << " ";
    return cout << endl, 0;
}