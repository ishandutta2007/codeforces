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

const int maxn=7e4+10,mod=1e9+7;
const ll inf=1e18;

pii p[maxn];
int par[maxn];
bitset<maxn> bs,tmp1,tmp2;
bool is[maxn];
int C[maxn],In[maxn];

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n,s;cin>>n>>s;
    for(int i=0;i<n;i++){
	cin>>p[i].F;
	p[i].S=i;
    }
    sort(p,p+n);
    bs[0]=1;
    for(int i=0;i<n-1;i++){
	tmp1=(bs<<p[i].F) | bs;
	tmp2=tmp1^bs;
	int id=tmp2._Find_first();
	while(id!=tmp2.size()){
	    par[id]=i;
	    id=tmp2._Find_next(id);
	}
	bs=tmp1;
    }
    s-=p[n-1].F;
    if(s<0 || !bs[s]) return cout<<-1<<endl,0;
    while(s>0){
	is[par[s]]=1;
	s-=p[par[s]].F;
    }
    int lst=-1;
    for(int i=0;i<n;i++){
	if(is[i])
	    C[p[i].S]=p[i].F,In[p[i].S]=-1;
	else if(lst==-1)
	    C[p[i].S]=p[i].F,In[p[i].S]=-1,lst=i;
	else
	    C[p[i].S]=p[i].F-p[lst].F,In[p[i].S]=p[lst].S,lst=i;
    }
    for(int i=0;i<n;i++){
	cout<<C[i]<<" ";
	if(In[i]==-1) cout<<0<<"\n";
	else          cout<<1<<" "<<In[i]+1<<"\n";
    }
    return 0;
}