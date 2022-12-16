// Faster!

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

const int maxn=510,Max=(1<<16)+10,Log=16,mod=1e9+7;

int cl[maxn],cr[maxn],pr[maxn],Cnt;
char type[maxn];
int dp[maxn][Max],tmp[Max],tmpl[Max],tmpr[Max];

void add(int id,int typ,int ccl,int ccr){
    type[id]=typ;
    cl[id]=ccl;
    cr[id]=ccr;
}

void Do(int *arr,int *start,bool bl){
    for(int i=0;i<Max;i++){
	arr[i]=start[i];
    }
    for(int i=0;i<Log;i++){
	for(int j=0;j<(1<<Log);j++){
	    if(bit(j,i)==bl) arr[j]=(arr[j]+arr[j ^ (1<<i)])%mod;
	}
    }
}

void dfs(int u){
    //    cout<<"HEY "<<u<<" "<<type[u]<<" "<<cl[u]<<" "<<cr[u]<<endl;
    if(cl[u]==-1 && cr[u]==-1){
	for(char ch='A';ch<='D';ch++){
	    if(type[u]!='?' && type[u]!=ch) continue;
	    int msk=0;
	    for(int j=0;j<16;j++)
		msk|= (bit(j,ch-'A')==1) << j;
	    dp[u][msk]++;
	}
	for(char ch='a';ch<='d';ch++){
	    if(type[u]!='?' && type[u]!=ch) continue;
	    int msk=0;
	    for(int j=0;j<16;j++)
		msk|= (bit(j,ch-'a')==0) << j;
	    dp[u][msk]++;
	}
	return;
    }
    dfs(cl[u]);
    dfs(cr[u]);
    for(int _=0;_<2;_++){
	if(type[u]!='?' && type[u]!=( _==0 ? '&' : '|' )) continue;
	Do(tmpl,dp[cl[u]],_);
	Do(tmpr,dp[cr[u]],_);
	for(int i=0;i<Max;i++)
	    tmp[i]=(__builtin_popcount(i) & 1 ? -1 : 1)*1ll*tmpl[i]*tmpr[i] %mod;
	Do(tmp,tmp,_);
	for(int i=0;i<Max;i++)
	    dp[u][i]=(dp[u][i]+ (__builtin_popcount(i) & 1 ? -1 : 1)*tmp[i]) %mod;
    }
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    memset(cl,-1,sizeof cl);
    memset(cr,-1,sizeof cr);
    string s;cin>>s;
    int nw=0;
    for(int i=0;i<sz(s);i++){
	if(s[i]==')'){
	    nw=pr[nw];
	}
	else if(s[i]=='('){
	    ++Cnt;
	    if(cl[nw]==-1) cl[nw]=Cnt;
	    else cr[nw]=Cnt;
	    pr[Cnt]=nw;
	    nw=Cnt;
	}
	else{
	    type[nw]=s[i];
	}
    }
    dfs(0);
    int n;cin>>n;
    int Yes=0,No=0;
    for(int i=0;i<n;i++){
	int a,b,c,d,val;cin>>a>>b>>c>>d>>val;
	int id=a + 2*b + 4*c + 8*d;
	if(val==0) No|=1<<id;
	else Yes|=1<<id;
    }
    int ans=0;
    for(int msk=0;msk<(1<<16);msk++){
	if((Yes & msk)!=Yes || (No & ((1<<16) -1 -msk))!=No) continue;
	ans=(ans+dp[0][msk]) %mod;
    }
    if(ans<0) ans+=mod;
    return cout<<ans<<endl,0;
}
// Deathly mistakes:
//  * Read the problem curfully.
//  * Check maxn.
//  * Overflows.