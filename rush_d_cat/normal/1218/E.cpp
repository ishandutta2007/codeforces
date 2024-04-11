#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 100000 + 10;
const int mod = 998244353, g = 3;
ll qpow(ll n,ll k){
    if(k<0) n = qpow(n,mod-2), k = -k;
	ll res = 1;
	while(k){
		if(k&1) res = res * n % mod;
		n = n * n % mod;
		k >>= 1;
	}
	return res;
}
int rev[N];
void get_rev(int bit){
	for(int i=0;i<(1<<bit);i++){
		rev[i] = (rev[i>>1]>>1)|((i&1)<<(bit-1));
	}
}
void ntt(vector<ll> &a,int n,int dft){
	for(int i=0;i<n;i++) if(i<rev[i]) swap(a[i],a[rev[i]]);
	for(int step=1;step<n;step<<=1){
		ll wn = qpow(g,dft*(mod-1)/(step*2));
		for(int j=0;j<n;j+=step<<1){
            ll wnk = 1;
            for(int k=j;k<j+step;k++){
				ll x = a[k] % mod, y = (wnk * a[k+step]) % mod;
				a[k] = (x + y) % mod;
				a[k+step] = ((x-y)%mod+mod)%mod;
				wnk = (wnk * wn) % mod;
            }
		}
	}
	if(dft==-1){
		int nl = qpow(n,mod-2);
		for(int i=0;i<n;i++) a[i] = a[i] * nl % mod;
	}
}
vector<ll> mul(vector<ll> a,vector<ll> b){
//    cout<<"-----"<<endl;
//    for(int i: a) cout<<i<<' '; cout<<endl;
//    for(int i: b) cout<<i<<' '; cout<<endl;
    int bit=0,s=1,alen=a.size(),blen=b.size();
    while(s<(alen+blen-1)) bit++, s<<=1;
    get_rev(bit);
    a.resize(s), b.resize(s);
    for(int i=alen;i<s;i++) a[i] = 0;
    for(int i=blen;i<s;i++) b[i] = 0;
    ntt(a,s,1), ntt(b,s,1);
    for(int i=0;i<s;i++) a[i] = a[i] * b[i] % mod;
    ntt(a,s,-1);
    a.resize(alen+blen-1);
//    for(int i: a) cout<<i<<' '; cout<<endl;
    return a;
}
ll a[N],b[N]; int n,k;
vector<ll> solve(int l,int r){
//	cout<<"solve "<<l<<' '<<r<<endl;
	if(l==r){
		return {1,b[l]};
	}
	int mid = (l + r) >> 1;
    vector<ll> L = solve(l,mid), R = solve(mid+1,r);
//    cout<<"merge "<<l<<' '<<r<<endl;
    vector<ll> res = mul(L,R);

    return res;
}
void solve(){
    for(int i=1;i<=n;i++) b[i] = a[i];
    int type; cin>>type;
    if(type==1){
		int q,p,d; cin>>q>>p>>d;
        b[p] = d;
		for(int i=1;i<=n;i++) b[i] = ((q - b[i])%mod+mod)%mod;
    }
    else{
        int q,l,r,d; cin>>q>>l>>r>>d;
        for(int i=l;i<=r;i++) b[i] += d;
		for(int i=1;i<=n;i++) b[i] = ((q - b[i])%mod+mod)%mod;
    }
//    for(int i=1;i<=n;i++) cout<<b[i]<<' '; cout<<endl;
    vector<ll> r = solve(1,n);
    cout<<r[k]<<endl;
}
int main(){
//	freopen("in.txt","r",stdin);
    cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
    int q; cin>>q;
    while(q--){
        solve();
    }
}