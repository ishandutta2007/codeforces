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

const int maxn=1e5+10,SQ=320,SQ2=1000,En=maxn-2;

int cnt[maxn];
int ccnt[maxn];
vector<int>big;
int nxt[maxn],val[maxn];

void Add(int x){
    ccnt[cnt[x]]--;
    ccnt[++cnt[x]]++;
}
void Era(int x){
    ccnt[cnt[x]]--;
    ccnt[--cnt[x]]++;
}

ll calc(){
    ll ans=0;
    
    sort(big.begin(),big.end(),[](int a,int b){return cnt[a]<cnt[b];});
    int pos=0;
    for(int i=1;i<SQ2;i++){
	if(ccnt[i]>0){
	    val[i]=ccnt[i];
	    nxt[pos]=i;
	    pos=i;
	}
    }
    for(int x:big){
	x=cnt[x];
	if(pos>=x) continue;
	if(ccnt[x]>0){
	    val[x]=ccnt[x];
	    nxt[pos]=x;
	    pos=x;
	}
    }
    nxt[pos]=En;
    pos=nxt[0];
    int pos2=0;
    while(pos<En){
	if(val[pos]==0) {pos=nxt[pos]; continue;}
	if(val[pos]>1){
	    while(nxt[pos2]<2*pos){
		pos2=nxt[pos2];
	    }
	    ans+=2ll*pos*(val[pos]/2);
	    if(nxt[pos2]==2*pos)
		val[2*pos]+=val[pos]/2;
	    else
		val[2*pos]=val[pos]/2,nxt[2*pos]=nxt[pos2],nxt[pos2]=2*pos;
	    val[pos]=val[pos]&1;
	}
	if(val[pos]==1){
	    int p=nxt[pos];
	    if(p==En) break;
	    while(nxt[pos2]<pos+p){
		pos2=nxt[pos2];
	    }
	    ans+=pos+p;
	    val[p]--,val[pos]--;
	    if(nxt[pos2]==pos+p)
		val[pos+p]++;
	    else
		val[pos+p]=1,nxt[pos+p]=nxt[pos2],nxt[pos2]=pos+p;
	}
	pos=nxt[pos];
    }
    return ans;
}

bool cmp(pair<pii,int>a,pair<pii,int>b){
    if(a.F.F/SQ != b.F.F/SQ) return a.F.F<b.F.F;
    return a.F.S<b.F.S;
}

pair<pii,int>p[maxn];
ll ans[maxn];
int a[maxn];

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    srand(time(0));
    int n;cin>>n;
    for(int i=0;i<n;i++){
	cin>>a[i];
	cnt[a[i]]++;
    }
    for(int i=0;i<maxn;i++){
	if(cnt[i]>=SQ2)
	    big.PB(i);
    }
    memset(cnt,0,sizeof cnt);
    int q;cin>>q;
    for(int i=0;i<q;i++){
	cin>>p[i].F.F>>p[i].F.S;
	--p[i].F.F;
	p[i].S=i;
    }
    sort(p,p+q,cmp);
    int l=0,r=0;
    for(int i=0;i<q;i++){
	int L=p[i].F.F,R=p[i].F.S;
	while(r<R) Add(a[r]),r++;
	while(L<l) l--,Add(a[l]);
	while(R<r) r--,Era(a[r]);
	while(l<L) Era(a[l]),l++;
	ans[p[i].S]=calc();
    }
    for(int i=0;i<q;i++){
	cout<<ans[i]<<"\n";
    }
    return 0;
}
// Deathly mistakes:
//  * Read the problem curfully.
//  * Check maxn.
//  * Overflows.