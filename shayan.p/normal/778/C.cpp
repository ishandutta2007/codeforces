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

const int maxn=3e5+10;

int nxt[26][maxn];
int smval[maxn],smh[maxn],SZ[maxn];
vector<int>vec2;

int calc(vector<int>vec){
    if(sz(vec)==0) return 0;
    if(sz(vec)==1) return SZ[vec.back()]-1;
    int ans=0;
    for(int i=0;i<26;i++){
	vec2.clear();
	for(int u:vec){
	    if(nxt[i][u]!=0)
		vec2.PB(nxt[i][u]);
	}
	if(sz(vec2)>0){
	    ans+=1+calc(vec2);
	}
    }
    return ans;
}

int prep(int u=1){
    SZ[u]=1;
    for(int i=0;i<26;i++){
	if(nxt[i][u]!=0)
	    SZ[u]+=prep(nxt[i][u]);
    }
    return SZ[u];
}

void dfs(int u=1,int h=1){
    vector<int>vec;
    for(int i=0;i<26;i++){
	if(nxt[i][u]!=0)
	    dfs(nxt[i][u],h+1),vec.PB(nxt[i][u]);
    }
    smh[h]++;
    smval[h]+=calc(vec);
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n;cin>>n;
    for(int i=0;i<n-1;i++){
	int a,b;
	char c;
	cin>>a>>b>>c;
	nxt[c-'a'][a]=b;
    }
    prep();
    dfs();
    int ans=n,ansid=-1;
    for(int i=1;i<maxn;i++){
	smh[i]+=smh[i-1];
	if(ans>smval[i]+smh[i])
	    ans=smval[i]+smh[i],ansid=i;
    }
    return cout<<ans<<endl<<ansid<<endl,0;
}
// Deathly mistakes:
//  * Read the problem curfully.
//  * Check maxn.
//  * Overflows.