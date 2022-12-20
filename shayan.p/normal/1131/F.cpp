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

const int maxn=2e5+10,mod=1e9+7;
const ll inf=1e18;

int par[maxn],st[maxn],fn[maxn],f[maxn];

int Find(int u){
    return par[u]<0?u:par[u]=Find(par[u]);
}
void Merge(int a,int b){
    //    cout<<"HEUAHD "<<a<<" "<<b<<"   ";
    a=Find(a),b=Find(b);
    assert(a!=b);
    //    cout<<a<<" "<<b<<"     ";
    int St=st[a],Fn=fn[b];
    //    cout<<"HEY "<<fn[a]<<" "<<st[b]<<" "<<f[fn[a]]<<endl;
    f[fn[a]]=st[b];
    if(par[a]>par[b]) swap(a,b);
    par[a]+=par[b];
    par[b]=a;
    st[a]=St,fn[a]=Fn;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n;cin>>n;
    for(int i=1;i<=n;i++){
	st[i]=fn[i]=i;
	par[i]=-1;
    }
    for(int i=1;i<n;i++){
	int a,b;cin>>a>>b;
	Merge(a,b);
    }
    int tmp=st[Find(1)];
    for(int i=1;i<=n;i++){
	//	cout<<i<<" "<<f[i]<<endl;
	cout<<tmp<<" ";
	tmp=f[tmp];
    }
    return cout<<endl,0;
}