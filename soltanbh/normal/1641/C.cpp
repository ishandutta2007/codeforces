#include <bits/stdc++.h>
using namespace std;
#define dbgv(v) cout<<#v<<" = "; f(i,0,v.size()) cout<<v[i]<<" "; cout<<endl
#define dbga(a,x,y) cout<<#a<<" = "; f(i,x,y) cout<<a[i]<<" "; cout<<endl
#define erorp(x) cout<<#x<<"={"<<(x.F)<<" , "<<x.S<<"}"<<endl
#define eror(x) cout<<#x<<'='<<(x)<<endl
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define f(i,a,b) for(int i=a;i<b;i++)
#define nb(x) __builtin_popcount(x)
#define all(v) v.begin(),v.end()
#define bit(n,k) (((n)>>(k))&1)
#define Add(x,y) x=(x+y)%mod
#define maxm(a,b) a=max(a,b)
#define minm(a,b) a=min(a,b)
#define lst(x) x[x.size()-1]
#define sz(x) int(x.size())
#define mp make_pair
#define ll long long
#define pb push_back
#define S second
#define F first
#define int ll

const int N=1e6+99;

int n,t,q,p[N],a[N],type[N],L[N],R[N];
pair<int,int> seg[N];
vector<int> ad[N],dl[N];


void build(){
	f_(i,n-1,1)	seg[i]=max(seg[i<<1],seg[i<<1|1]);
}
pair<int,int> get(int l, int r){
	//l--,r--;
	l--,r--;
	pair<int,int> res={0,0};
	for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
		if (l&1){
			maxm(res,seg[l++]);
		}
		if (r&1){
			maxm(res,seg[--r]);
		}
	}
	return res;
}

void Main(){
	cin>>n>>q;
	f(i,1,q+1){
		cin>>type[i];
		if(type[i]==0){
			cin>>L[i]>>R[i]>>a[i];
			if(a[i]==1) continue ;
			ad[L[i]].pb(i);
			dl[R[i]].pb(i);			
		}
		else{
			cin>>a[i];
		}
	}
	set<int> s;
	f(i,1,n+1){
		p[i]=q+10;
		for(auto x : ad[i]) s.insert(x);
		seg[i+n-1].S=i;
		if(s.size()==0) seg[i+n-1].F=N;
		else seg[i+n-1].F=*s.begin();
		for(auto x : dl[i]) s.erase(x);
	}
	build();
	f(i,1,q+1){
		if(type[i]==0 && a[i]==1){
			int pos=get(L[i],R[i]+1).S;
			minm(p[pos],max(i,max(get(L[i],pos).F,get(pos+1,R[i]+1).F)));
		}
	}
	f(i,1,q+1){
		if(type[i]==1){
			if(seg[a[i]+n-1].F<=i){
				cout<<"NO"<<endl;
			}
			else{
				if(p[a[i]]<=i){
					//eror(p[a[i]]);
					cout<<"YES"<<endl;
				}
				else{
					cout<<"N/A"<<endl;
				}
			}
		}
	}
}

main(){
	ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
	t=1;
	while(t--){
		Main();
	}
}