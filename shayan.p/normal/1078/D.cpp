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

const int maxn=3e5+10,mod=1e9+7;
const ll inf=1e18;

int dpl[20][maxn],dpr[20][maxn],sp[20][maxn],a[maxn];
int ans[maxn];
pii seg[maxn],seg2[maxn];

pii ask(int a,int b){
    int id=31-__builtin_clz(b-a+1);
    return {sp[id][a],sp[id][b-(1<<id)+1]};
}

int main(){
    int n;cin>>n;
    for(int i=0;i<n;i++){
	cin>>a[i];
	a[i+n]=a[i];
	a[i+n+n]=a[i];
    }
    int N=3*n;
    for(int i=0;i<N;i++){
	dpl[0][i]=max(0,i-a[i]);
	dpr[0][i]=min(N-1,i+a[i]);
    }
    for(int i=1;i<20;i++){
	memset(sp,63,sizeof sp);
	for(int j=0;j<N;j++)
	    sp[0][j]=dpl[i-1][j];
	for(int k=1;k<20;k++)
	    for(int j=0;j<N;j++)
		sp[k][j]=min(sp[k-1][j],sp[k-1][min(j+(1<<(k-1)),N-1)]);
	for(int j=0;j<N;j++){
	    pii p=ask(dpl[i-1][j],dpr[i-1][j]);
	    dpl[i][j]=min(p.F,p.S);
	}
	
	memset(sp,0,sizeof sp);
	for(int j=0;j<N;j++)
	    sp[0][j]=dpr[i-1][j];
	for(int k=1;k<20;k++)
	    for(int j=0;j<N;j++)
		sp[k][j]=max(sp[k-1][j],sp[k-1][min(j+(1<<(k-1)),N-1)]);
	for(int j=0;j<N;j++){
	    pii p=ask(dpl[i-1][j],dpr[i-1][j]);
	    dpr[i][j]=max(p.F,p.S);
	}
    }
    for(int i=0;i<n;i++){
	seg[i]={i+n,i+n};
    }
    for(int i=19;i>=0;i--){
	memset(sp,63,sizeof sp);
	for(int j=0;j<N;j++)
	    sp[0][j]=dpl[i][j];
	for(int k=1;k<20;k++)
	    for(int j=0;j<N;j++)
		sp[k][j]=min(sp[k-1][j],sp[k-1][min(j+(1<<(k-1)),N-1)]);
	for(int j=0;j<n;j++){
	    pii p=ask(seg[j].F,seg[j].S);
	    seg2[j].F=min(p.F,p.S);
	}

	memset(sp,0,sizeof sp);
	for(int j=0;j<N;j++)
	    sp[0][j]=dpr[i][j];
	for(int k=1;k<20;k++)
	    for(int j=0;j<N;j++)
		sp[k][j]=max(sp[k-1][j],sp[k-1][min(j+(1<<(k-1)),N-1)]);
	for(int j=0;j<n;j++){
	    pii p=ask(seg[j].F,seg[j].S);
	    seg2[j].S=max(p.F,p.S);
	}

	for(int j=0;j<n;j++){
	    if((seg2[j].S-seg2[j].F+1)<n)
		ans[j]+=(1<<i),seg[j]=seg2[j];
	}
    }
    for(int i=0;i<n;i++){
	cout<<ans[i]+(n!=1)<<" ";
    }
    cout<<endl;
    return 0;
}