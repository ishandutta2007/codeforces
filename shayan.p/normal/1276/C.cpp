// They can't break me, as long as I know who I am...

#include<bits/stdc++.h>

#define F first
#define S second
#define PB push_back
#define sz(s) int((s).size())
#define bit(n,k) (((n)>>(k))&1)

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int maxn = 1e5 + 10, mod = 1e9 + 7;
const ll inf = 1e18;

map<int, int> mpp;
vector<pii> mp;
vector<int> vec;
vector<int> ansv[maxn];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie();

    int n; cin>>n;
    for(int i = 0; i < n; i++){
	int x; cin>>x;
	mpp[x]++;
    }
    for(auto p: mpp)
	mp.PB(p);
    sort(mp.begin(), mp.end(), [](pii a, pii b){ return a.S > b.S; } );
    
    int ans = 0, ln = 0;
    
    for(int i = 1; i * i <= n; i++){
	int num = 0;
	for(auto p : mp){
	    num+= min(p.S, i);
	}
	num-= num %i;
	if((num / i) < i)
	    continue;
	if(ans < num)
	    ans = num, ln = i;
    }
    for(auto p : mp){
	int num = min(ln, p.S);
	while(sz(vec) < ans && num){
	    vec.PB(p.F);
	    num--;
	}
    }

    int A = ln, B = ans / ln;
    for(int i = 0; i < A; i++)
	ansv[i].resize(B);
    int pt = 0;
    for(int i = 0; i < B; i++){
	for(int j = 0; j < A; j++){
	    ansv[j][(i + j) % B] = vec[pt++];
	}
    }

    cout << ans <<"\n"<< A <<" "<< B<<"\n";
    for(int i = 0; i < A; i++)
	for(int j = 0; j < B; j++)
	    cout << ansv[i][j] << " \n"[j==B-1];
    return 0;
}
// #pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")