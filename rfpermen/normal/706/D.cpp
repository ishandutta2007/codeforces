#include <bits/stdc++.h>
 
#pragma GCC optimize("O3")
using namespace std;
#define ll long long
#define ull unsigned long long
#define rep(i,n,N) for(ll i=n;i<=N;++i)
#define rap(i,n,N) for(ll i=n;i>=N;--i)
#define mp make_pair
#define pb push_back
#define pob pop_back
#define pf push_front
#define pof pop_front
#define fi first
#define se second
#define ff fi.fi
#define fs fi.se
#define sf se.fi
#define ss se.se
#define lc (id<<1)
#define rc ((id<<1)|1)
#define db(x) cout << ">>>>>> " << #x << " -> " << x << endl
#define all(x) x.begin(),x.end()
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define piii pair<int,pii>
#define piiii pair<pii,pii>
#define psi pair<string,int>
#define endl "\n"
const int MAX = 2e5+5;
const ll MAX2 = 11;
const ll MOD = 998244353;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 450;
 
int q,x,id;
char c;
bool st;
struct trie{
	int nx[2],cnt;
}tr[MAX*30];

inline void ins(int z,int nw){
	while(z>=0){
		st = x&(1<<z);
		if(!tr[nw].nx[st])tr[nw].nx[st] = ++id;
		--z, nw = tr[nw].nx[st];
		++tr[nw].cnt;
	}
	return;
}
inline void del(int z,int nw){
	while(z>=0){
		st = x&(1<<z);
		if(!tr[nw].nx[st])tr[nw].nx[st] = ++id;
		--z, nw = tr[nw].nx[st];
		--tr[nw].cnt;
	}
	return;
}
int ret;
inline int ser(int z,int nw){
	ret = 0;
	while(z>=0){
		st = x&(1<<z);
		st^=1;
		if(!tr[nw].nx[st]||!tr[tr[nw].nx[st]].cnt)nw = tr[nw].nx[st^1];
		else ret|=(1<<z), nw = tr[nw].nx[st];
		--z;
	}
	return ret;
}

int main(){
//	cout<<fixed<<setprecision(10);
//    freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>q;
    ins(29,0);
    while(q--){
    	cin>>c>>x;
    	if(c=='+')ins(29,0);
    	else if(c=='-')del(29,0);
    	else cout<<ser(29,0)<<endl;
	}
	return 0;
}