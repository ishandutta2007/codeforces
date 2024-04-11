// And you curse yourself for things you never done
// Shayan.P  2020-08-16

#include<bits/stdc++.h>

#define F first
#define S second
#define PB push_back
#define sz(s) int((s).size())
#define bit(n,k) (((n)>>(k))&1)

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

const int maxn = 1e6 + 10, maxk = 21, mod = 1e9 + 7, inf = 1e9 + 10;

pii p[maxn];
int mA, mB;
int n, m, k;

int prm[maxk], tmp[maxk];
int a[2][maxn];

void readMsk(int &ans){
    string s;
    cin >> s;
    for(int i = 0; i < k; i++)
	ans+= (s[i] == '1') << i;
}
void inv(){
    for(int i = 0; i < k; i++)
	tmp[ prm[i] ] = i;
    memcpy(prm, tmp, sizeof prm);
}

int mx[1<<maxk], mn[1<<maxk];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie();

    cin >> n >> m >> k;
    readMsk(mA), readMsk(mB);
    for(int i = 0; i < n; i++){
	cin >> p[i].F >> p[i].S;
	--p[i].F, --p[i].S;
    }
    iota(prm, prm + k, 0);
    for(int i = 0; i < n; i++){
	for(int j = 0; j < k; j++)
	    a[0][i]+= bit(mA, prm[j]) << j;
	inv();
	swap(prm[p[i].F], prm[p[i].S]);
	inv();
    }
    iota(prm, prm + k, 0);
    for(int i = 0; i < n; i++){
	swap(prm[p[i].F], prm[p[i].S]);
    }
    for(int i = n-1; i >= 0; i--){
	inv();
	for(int j = 0; j < k; j++)
	    a[1][i]+= bit(mB, prm[j]) << j;
	inv();
	swap(prm[p[i].F], prm[p[i].S]);
    }
    for(int i = 0; i < (1<<k); i++){
	mn[i] = inf, mx[i] = -inf;
    }
    for(int i = 0; i < n; i++){
	mn[a[0][i]] = min(mn[a[0][i]], i);
	mx[a[1][i]] = max(mx[a[1][i]], i);
    }
    for(int i = 0; i < k; i++){
	for(int msk = (1<<k)-1; msk >= 0; msk--){
	    if(bit(msk, i)){
		mx[msk ^ (1<<i)] = max(mx[msk ^ (1<<i)], mx[msk]);
		mn[msk ^ (1<<i)] = min(mn[msk ^ (1<<i)], mn[msk]);
	    }
	}
    }
    pair<int, pii> ans = {-1, {-1, -1}};    
    for(int msk = 0; msk < (1<<k); msk++){
	if(mx[msk] - mn[msk] + 1 >= m)
	    ans = max(ans, {__builtin_popcount(msk), {mn[msk], mx[msk]}});
    }
    return cout << 2 * ans.F - __builtin_popcount(mB) + k - __builtin_popcount(mA) << endl << ans.S.F+1 << " " << ans.S.S+1 << endl, 0;
}