// Remember...

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

const int maxn1=(800 * 10 * 2) + 10, maxn2=2010;

string L,R;

pii sg[maxn1];
char bst[maxn2][maxn1];
int dp[maxn1], pre[maxn1];

int nxt[maxn1][10], f[maxn1], val[maxn1], h[maxn1], C;

void go(int vert=0,int len=0,bool LL=1,bool RR=1){
    if((LL==0 && RR==0) || len==sz(L)){
	int l=sz(L)-len, r=sz(R)-len;
	assert(sg[vert].F == -1);
	sg[vert]={l,r};
	return;
    }
    for(int i=0;i<10;i++){
	if(LL && L[len]-'0' > i) continue;
	if(RR && R[len]-'0' < i) continue;
	if(nxt[vert][i]==0) nxt[vert][i]=++C;
	go(nxt[vert][i], len+1, L[len]-'0' < i ? 0 : LL, R[len]-'0' > i ? 0 : RR);
    }
}
void gol(int vert=0,int len=0,bool LL=1){
    if(LL==0 || len==sz(L)){
	int l=sz(L)-len, r=sz(L)-len;
	assert(sg[vert].F == -1);
	sg[vert]={l,r};
	return;
    }
    for(int i=0;i<10;i++){
	if(LL && L[len]-'0' > i) continue;
	if(nxt[vert][i]==0) nxt[vert][i]=++C;
	gol(nxt[vert][i], len+1, L[len]-'0' < i ? 0 : LL);
    }
}
void gor(int vert=0,int len=0,bool RR=1){
    if(RR==0 || len==sz(R)){
	int l=max(0,sz(L)-len+1), r=sz(R)-len;
	assert(sg[vert].F == -1 || sg[vert].S+1 == l);
	if(sg[vert].F == -1) sg[vert]={l,r};
	else sg[vert].S=r;
	return;
    }
    for(int i=0;i<10;i++){
	if(len==0 && i==0) continue;
	if(RR && R[len]-'0' < i){
	    if(len+1>=sz(R)) continue;
	    if(nxt[vert][i]==0) nxt[vert][i]=++C;

	    int l=max(0,sz(L)-len), r=sz(R)-1-len-1, vv=nxt[vert][i];
	    assert(sg[vv].F == -1 || sg[vv].S+1 == l);
	    if(sg[vv].F == -1) sg[vv]={l,r};
	    else sg[vv].S=r;
	    
	    continue;
	}
	if(nxt[vert][i]==0) nxt[vert][i]=++C;
	gor(nxt[vert][i], len+1, R[len]-'0' > i ? 0 : RR);
    }
}

void build(){
    queue<int> q;
    for(int i=0;i<10;i++){
	if(nxt[0][i])
	    q.push(nxt[0][i]), h[nxt[0][i]]=1;
    }
    while(sz(q)){
	int u=q.front();
	q.pop();
	
	for(int i=0;i<10;i++){
	    if(nxt[u][i]) f[ nxt[u][i] ]= nxt[ f[u] ][i], h[nxt[u][i]]= h[u]+1, q.push(nxt[u][i]);
	    else          nxt[u][i]= nxt[ f[u] ][i];
	}
    }
}

void rebuild(int ln){
    for(int i=0;i<=C;i++){
	val[i]= (sg[i].F==-1 || sg[i].F>ln) ? 0 : ( min(ln,sg[i].S) - sg[i].F + 1);
    }
    
    queue<int> q;
    q.push(0);
    while(sz(q)){
	int u=q.front();
	q.pop();
	val[u]+= val[ f[u] ];
	for(int i=0;i<10;i++){
	    if(h[ nxt[u][i] ] == h[u]+1){
		q.push(nxt[u][i]);
	    }
	}
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie();

    fill(sg,sg+maxn1,(pii){-1,-1});
    
    cin>>L>>R;
    reverse(L.begin(), L.end());
    reverse(R.begin(), R.end());
    while(L.back()=='0') L.pop_back();
    while(R.back()=='0') R.pop_back();
    reverse(L.begin(), L.end());
    reverse(R.begin(), R.end());

    if(sz(L) == sz(R)){
	go();
    }
    else{
	gol(), gor();
    }
    build();
    
    int n; cin>>n;
    
    for(int i=1;i<=n;i++){
	memcpy(pre,dp,sizeof pre);

	rebuild(i-1);
	for(int u=0;u<=C;u++){
	    dp[u]=-1, bst[i][u]='0';
	    for(int j=0;j<10;j++){
		int num=val[ nxt[u][j] ] + pre[ nxt[u][j] ];
		if(num > dp[u]) dp[u]=num, bst[i][u]= '0'+j; // lexo minimum
	    }
	}
    }

    string ans="";
    int tmp=0;
    for(int i=n;i>=1;i--){
	ans+=bst[i][tmp];
	tmp=nxt[tmp][ ans.back()-'0' ];
    }
    return cout<<dp[0]<<"\n"<<ans<<endl,0;
}
// Deathly mistakes:
//  * Read the problem carefully.
//  * Check maxn.
//  * Overflows.


// #pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")