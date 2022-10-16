#include<bits/stdc++.h>
#define ll long long
#define rep(i,n,N) for(int i = n; i<=N; ++i)
#define asd(i,n,N) for(int i = n; i< N; ++i)
#define rap(i,n,N) for(int i = n; i>=N; --i)
#define pb push_back
#define mems(a,b) memset(a,b,sizeof a)
#define all(x) x.begin(),x.end()
#define db(x) cout << ">>> " << #x << " = " << x << endl
#define lc (id<<1)
#define rc ((id<<1)|1)
#define pii pair<int,int>
#define pll pair<ll,ll>
#define plll pair<ll,pll>
#define fi first
#define se second
#define sf se.fi
#define ss se.se

using namespace std;

const int MAX = 2e5+5;
const ll MOD = 1000000007;
const ll MOD2 = 1000000009;
const ll key = 36671;

ll n,x,y,a,b;
plll z[MAX];

inline bool cmp(plll a,plll b){
	if(a.sf==b.sf)return a.ss>b.ss;
	return a.sf<b.sf;
}

int main(){
//	freopen("input.txt","r",stdin);
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin>>n;
	rep(i,1,n){
		cin>>x;
		y = x;
		a = b = 0;
		while(y%2==0)++a, y>>=1;
		while(y%3==0)++b, y/=3;
		z[i] = {x,{a,b}};
	}
	sort(z+1,z+1+n,cmp);
	rep(i,1,n)cout<<z[i].fi<<' '; cout<<endl;
	return 0;
}