// Wanna Hack? GL...

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

const int maxn=1e5+10,inf=1e9;

int p[maxn],tmp[maxn];
int val[maxn],f[maxn],dp[maxn];
vector<vector<int> >Ans;
vector<int>vec;

int Lis(int n){
    val[0]=0;
    int ls=0;
    for(int i=1;i<=n;i++){
	dp[i]=upper_bound(val,val+ls+1,p[i])-val;
	ls=max(ls,dp[i]);
	f[p[i]]=val[dp[i]-1];
	val[dp[i]]=p[i];
    }
    return ls;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    int q;cin>>q;
    while(q--){
	Ans.clear();
	int n,ans=0,Num=0;cin>>n;
	for(int i=1;i<=n;i++){
	    cin>>p[i];
	}
	while(Num<=n){
	    Num+=++ans;
	}
	--ans;
	while(n>0){
	    int ls=Lis(n);
	    if(ls<=ans){
		int id=sz(Ans);
		vec.clear();
		for(int i=0;i<ls;i++){
		    Ans.PB(vec);
		}
		for(int i=1;i<=n;i++){
		    Ans[id+dp[i]-1].PB(p[i]);
		}
		n=0;
	    }
	    else{
		--ans;
		vec.clear();
		int x=val[ls],C=1,pos=n;
		while(p[pos]!=x)
		    tmp[C++]=p[pos--];
		while(x>0){
		    vec.PB(x),--pos,x=f[x];
		    while(p[pos]!=x)
			tmp[C++]=p[pos--];
		}
		n-=ls;
		for(int i=1;i<=n;i++){
		    p[i]=tmp[n+1-i];
		}
		reverse(vec.begin(),vec.end());
		Ans.PB(vec);
	    }
	}
	cout<<sz(Ans)<<"\n";
	for(auto IT:Ans){
	    cout<<sz(IT)<<" ";
	    for(int x:IT)
		cout<<x<<" ";
	    cout<<"\n";
	}
    }
}