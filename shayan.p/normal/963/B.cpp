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

const int maxn=2e5+10,mod=1e9+7;
const ll inf=1e18;

vector<int>v[maxn];
int fn[maxn],dg[maxn],C=1;
bool del[maxn];
set<pii>s;

void dfs(int u,int par=-1){
    for(int y:v[u]){
	if(y!=par){
	    dfs(y,u);
	}
    }
    fn[u]=C++;
}

void Erase(int u){
    cout<<u<<endl;
    dg[u]=0;
    del[u]=1;
    s.erase({fn[u],u});
    for(int y:v[u]){
	if(!del[y]){
	    if((--dg[y])&1){
		s.erase({fn[y],y});
	    }
	    else{
		s.insert({fn[y],y});
	    }
	}
    }
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n;cin>>n;
    for(int i=1;i<=n;i++){
	int x;cin>>x;
	if(x!=0){
	    v[i].PB(x);
	    v[x].PB(i);
	}
    }
    if((n&1)==0){
	return cout<<"NO"<<endl,0;
    }
    cout<<"YES"<<endl;
    for(int i=1;i<=n;i++){
	dg[i]=sz(v[i]);
    }
    dfs(1);
    for(int i=1;i<=n;i++){
	if((dg[i]&1)==0){
	    s.insert({fn[i],i});
	}
    }
    while(sz(s)){
	Erase(s.begin()->S);
    }
    return 0;
}