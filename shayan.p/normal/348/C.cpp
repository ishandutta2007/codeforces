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

const int maxn=1e5+10,SQ=350;

bool is[maxn];
int cnt[SQ][maxn];
ll other[maxn],delta[maxn],pre[maxn],a[maxn];
vector<int>v[maxn],big;

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n,m,q;cin>>n>>m>>q;
    for(int i=0;i<n;i++)
	cin>>a[i];
    for(int i=0;i<m;i++){
	int S;cin>>S;
	while(S--){
	    int x;cin>>x;
	    v[i].PB(--x);
	    pre[i]+=a[x];
	}
	if(sz(v[i])>=SQ)
	    big.PB(i);
    }
    for(int w=0;w<sz(big);w++){
	int id=big[w];
	for(int x:v[id])
	    is[x]=1;
	for(int i=0;i<m;i++)
	    for(int x:v[i])
		cnt[w][i]+=is[x];
	for(int x:v[id])
	    is[x]=0;
    }
    while(q--){
	char ch;cin>>ch;
	int id;cin>>id;
	--id;
	if(ch=='+'){
	    int x;cin>>x;
	    for(int i=0;i<sz(big);i++)
		other[big[i]]+=1ll*cnt[i][id]*x;
	    if(sz(v[id])<SQ){
		for(int ID:v[id])
		    a[ID]+=x;
	    }
	    else{
		delta[id]+=x;
	    }
	}
	else{
	    ll ans=0;
	    if(sz(v[id])>=SQ){
		ans=pre[id]+other[id];
	    }
	    else{
		for(int ID:v[id])
		    ans+=a[ID];
		for(int i=0;i<sz(big);i++)
		    ans+=1ll*cnt[i][id]*delta[big[i]];
	    }
	    cout<<ans<<endl;
	}
    }
    return 0;
}