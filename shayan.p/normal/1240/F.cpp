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

const int maxn=1010,mod=1e9+7;
const ll inf=1e18;

int id1[maxn], id2[maxn], cnt1[maxn], cnt2[maxn];
int to1[maxn][maxn], to2[maxn][maxn], ans[maxn];

vector<pii> vec;

void add(int a,int b){
    vec.PB({a,b});
    int both=-1, A=-1, B=-1;
    for(int i=0;i<maxn;i++){
	if(both==-1 && to1[a][i]==-1 && to2[b][i]==-1) both=i;
	if(A==-1 && to1[a][i]!=-1 && to2[b][i]==-1) A=i;
	if(B==-1 && to1[a][i]==-1 && to2[b][i]!=-1) B=i;	
    }
    if(A!=-1 && B!=-1){
	int tmp=a;
	bool side=0;
	while(true){
	    if(side==0){
		swap(to1[tmp][A], to1[tmp][B]);
		if(to1[tmp][B]==-1) break;
		tmp=vec[ to1[tmp][B] ].S;
	    }
	    else{
		swap(to2[tmp][A], to2[tmp][B]);
		if(to2[tmp][A]==-1) break;
		tmp=vec[ to2[tmp][A] ].F;
	    }
	    side^=1;
	}
	to1[a][A]= to2[b][A]= sz(vec)-1;
    }
    else{
	assert(both!=-1);
	to1[a][both]= to2[b][both] =sz(vec)-1;	
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie();

    memset(to1,-1,sizeof to1);
    memset(to2,-1,sizeof to2);
    
    int n,m,k; cin>>n>>m>>k;
    for(int i=1;i<=n;i++){
	int x; cin>>x;
    }
    int N1=1, N2=1;
    for(int i=1;i<=n;i++){
	id1[i]=N1++;
	id2[i]=N2++;
    }
    for(int i=1;i<=m;i++){
	int a,b; cin>>a>>b;
	add(id1[a], id2[b]);
	if(++cnt1[id1[a]] == k)
	    id1[a]=N1++;
	if(++cnt2[id2[b]] == k)
	    id2[b]=N2++;
    }
    for(int i=1;i<=N1;i++){
	for(int j=0;j<maxn;j++){
	    if(to1[i][j]!=-1) ans[ to1[i][j] ]=j;
	}
    }
    for(int i=0;i<m;i++){
	cout<<ans[i]+1<<"\n";
    }
    return 0;
}
// Deathly mistakes:
//  * Read the problem carefully.
//  * Check maxn.
//  * Overflows.


// #pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")