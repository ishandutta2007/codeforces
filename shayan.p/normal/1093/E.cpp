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

const int maxn=2e5+10,mod=1e9+7,SQ1=1400,SQ2=145;
const ll inf=1e18;

struct fenwick{
    int sm[maxn];
    void add(int ind,int x){
	while(ind<maxn)
	    sm[ind]+=x,ind+=(ind & -ind);
    }
    int ask(int ind){
	int ans=0;
	while(ind>0)
	    ans+=sm[ind],ind-=(ind & -ind);
	return ans;
    }
    int ask(int l,int r){
	return ask(r)-ask(l-1);
    }
};fenwick fn[SQ2];
    
int a[maxn],b[maxn];

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n,q;cin>>n>>q;
    for(int i=1;i<=n;i++){
	int x;cin>>x;
	a[x]=i;
    }
    for(int i=1;i<=n;i++){
	cin>>b[i];
	b[i]=a[b[i]];
    }
    for(int i=1;i<=n;i++){
	fn[i/SQ1].add(b[i],1);
    }
    while(q--){
	int task;cin>>task;
	if(task==1){
	    int l,r,f,s,ans=0;cin>>l>>r>>f>>s;
	    for(int i=0;i*SQ1<=s;i++){
		if(max(f,i*SQ1)>min(s,i*SQ1+SQ1-1)) continue;
		if(f<=i*SQ1 && i*SQ1+SQ1-1<=s){
		    ans+=fn[i].ask(l,r);
		}
		else{
		    for(int pt=max(f,i*SQ1);pt<=min(s,i*SQ1+SQ1-1);pt++){
			ans+=(l<=b[pt] && b[pt]<=r);
		    }
		}
	    }
	    cout<<ans<<"\n";
	}
	else{
	    int x,y;cin>>x>>y;
	    int id1=x/SQ1,id2=y/SQ1;
	    if(id1!=id2){
		fn[id1].add(b[x],-1);
		fn[id1].add(b[y],1);
		fn[id2].add(b[y],-1);
		fn[id2].add(b[x],1);
	    }
	    swap(b[x],b[y]);
	}  
    }
    return 0;
}