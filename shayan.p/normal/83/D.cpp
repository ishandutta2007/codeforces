// Phoenix

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

const int maxn=5e4;

bool mark[maxn];
vector<int>vec;

int f(int n,int p){
    if(n<p) return n>=1;
    int ans=n;
    for(int i=0;vec[i]<p;i++){
	ans-=f(n/vec[i],vec[i]);
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    int a,b,p;cin>>a>>b>>p;
    for(int i=2;i*i<=p;i++){
	if(p%i==0)
	    return cout<<0<<endl,0;
    }
    if(p>=maxn){
	return cout<<(b>=p)-(a>p)<<endl,0;
    }
    for(int i=2;i<=p;i++){
	if(!mark[i]){
	    vec.PB(i);
	    for(int j=i;j<=p;j+=i)
		mark[j]=1;
	}
    }
    return cout<<f(b/p,p)-f((a-1)/p,p)<<endl,0;
}