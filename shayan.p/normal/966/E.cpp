// Remember...

#include<bits/stdc++.h>

#define F first
#define S second
#define PB push_back
#define sz(s) int((s).size())
#define bit(n,k) (((n)>>(k))&1)

//#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int maxn=1e5+10, SQ=155;

vector<int> v[maxn], vec, verts[2*SQ];
int pr[maxn], a[maxn], qr[maxn], npr[maxn];
bool is[maxn], is2[maxn], mark[maxn];

int memo[2*SQ][2*maxn], C, id[maxn], lz[2*SQ], neg[2*SQ], NEG;

int &cnt(int i,int j){
    return memo[i][j+maxn-5];
}
int prep(int u=1,int npar=0){
    int ans=-1;
    if(is2[u]){
	vec.PB(u);
	npr[u]=npar;
	npar=u;
	id[u]=C++;
	ans=u;
    }
    for(int y:v[u]){
	int x=prep(y,npar);
	if(ans==-1 && x!=-1) ans=x;
    }
    if(mark[u]){
	verts[id[ans]].PB(u);
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie();
    
    int n,q;
#ifdef shayan
    srand(time(0));	
    n= q= 100000;
#else
    cin>>n>>q;
#endif

    for(int i=2;i<=n;i++){
#ifdef shayan
	pr[i]=i-1;
#else
	cin>>pr[i];
#endif	
	v[pr[i]].PB(i);
    }
    for(int i=1;i<=n;i++){
#ifdef shayan
	a[i]= rand()%n;
#else
	cin>>a[i];
#endif
    }
    for(int i=0;i<q;i++){
#ifdef shayan
	qr[i]= 1+(rand()%n); // alamat!
#else
	cin>>qr[i];
#endif
    }
    for(int l=0;l<q;l+=SQ){// clean it after use
	memset(is2,0,sizeof is2);
	memset(mark,0,sizeof mark);
	memset(lz,0,sizeof lz);
	memset(neg,0,sizeof neg);
	
	vec.clear();
	C=NEG=0;

	for(int i=0;i<2*SQ;i++){
	    verts[i].clear();
	}
	
	int r=min(l+SQ, q);
	is2[1]=mark[1]=1;
	
	for(int i=l;i<r;i++){
	    int u=abs(qr[i]);
	    is2[u]=1;
	    while(mark[u]==0){
		mark[u]=1;
		u=pr[u];
	    }
	    is2[u]=1;
	}
	for(int i=1;i<=n;i++){
	    if(mark[i]==0 && is[i]==0)
		NEG+= a[i]<0;	    
	}
	
	prep();

	for(int i=0;i<C;i++){
	    for(int u:verts[i]){
		if(is2[u] || is[u]==0){
		    cnt(i,a[u])++;
		    neg[i]+= a[u]<0;
		}
	    }
	}
	
	for(int i=l;i<r;i++){
	    int u=abs(qr[i]);
	    is[u]^=1;
	    bool IS=is[u];
	    while(u){
		int ID= id[u];
		if(IS){// add
		    lz[ID]--;
		    neg[ID]+= cnt(ID,-lz[ID]-1);
		}
		else{// rem
		    lz[ID]++;
		    neg[ID]-= cnt(ID,-lz[ID]);
		}
		u=npr[u];
	    }
	    int ans=0;
	    for(int u:vec){		
		ans+= neg[id[u]];
		if(a[u]+lz[ id[u] ]<0 && is[u]==1) ans--;
	    }
	    cout<<ans+NEG<<" ";
	}
	
	for(int i=0;i<C;i++){
	    for(int u:verts[i]){
		if(is2[u] || is[u]==0)
		    cnt(i,a[u])--;
		a[u]+=lz[i];
	    }
	}
    }
    return cout<<endl,0;
}
// Deathly mistakes:
//  * Read the problem carefully.
//  * Check maxn.
//  * Overflows.