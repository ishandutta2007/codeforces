// Jump, and you will find out how to unfold your wings as you fall.

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

const int maxn=2010;

int n,m,C;
vector<pii>ans;
vector<int>v[maxn];
bitset<maxn>bs[maxn],bs2[maxn],total[maxn],comp[maxn],tmp,tmp2,mark1,mark2;
bool NO;

queue<pii>q;

bool solve(int u){
    mark1=0,mark2=0;
    for(int i=0;i<m;i++){
	if(bs[i][u]==0)
	    mark2[i]=1;
    }
    mark1=total[u],mark1[u]=0;

    C=0;
    while(mark1.any()){
	int u=mark1._Find_first();
	q.push({u,1});
	mark1[u]=0;
	comp[C]=0,comp[C][u]=1;
	while(sz(q)){
	    int u=q.front().F,wh=q.front().S;
	    q.pop();
	    if(wh==1)
		tmp=mark2 & bs2[u];
	    else
		tmp=mark1 & bs[u];
	    for(int y=tmp._Find_first();y!=tmp.size();y=tmp._Find_next(y)){
		if(wh==1)
		    mark2[y]=0,q.push({y,2});
		else
		    mark1[y]=0,q.push({y,1}),comp[C][y]=1;
	    }
	}
	C++;
    }
    
    tmp=total[u];
    for(int i=0;i<m;i++){
	if(bs[i][u]==1){
	    for(int j=0;j<C;j++){
		tmp2=bs[i]&comp[j];
		if(!tmp2.any()){
		    bs[i]|=comp[j];
		}
	    }
	    tmp&=bs[i];
	}
    }
    for(int i=0;i<C;i++){
	tmp2=tmp&comp[i];
	if(!tmp2.any()) return 0;
	int y=tmp2._Find_first();
	total[y]=comp[i];
	ans.PB({u,y});
	v[u].PB(y);
    }
    for(int y:v[u]){
	total[u]^=total[y];
	if(!solve(y))
	    return 0;
    }
    total[u][u]=0;
    for(int i=total[u]._Find_first();i<int(total[u].size());i=total[u]._Find_next(i)){
	ans.PB({u,i});
    }
    return 1;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    int q;cin>>q;
    while(q--){
	cin>>n>>m;
	for(int i=0;i<m;i++){
	    cin>>bs[i];
	}
	for(int i=0;i<n;i++){
	    for(int j=0;j<m;j++){
		bs2[i][j]=bs[j][i];
	    }
	}
	total[0]=0;
	ans.clear();
	for(int i=0;i<n;i++){
	    total[0][i]=1;
	    v[i].clear();
	}
	if(solve(0)){
	    cout<<"YES\n";
	    for(pii p:ans){
		cout<<n-p.F<<" "<<n-p.S<<"\n";
	    }
	}
	else{
	    cout<<"NO\n";
	}
    }
}
// Deathly mistakes:
//  * Read the problem curfully.
//  * Check maxn.
//  * Overflows.