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

const int maxn=5e5+10,inf=1e9;

int nxt[maxn],cnt[maxn],sm[maxn],sp[20][maxn];
int rnk[20][maxn],n;
pair<pii,int>p[maxn];

int LCP(int a,int b){
    int ans=0;
    for(int i=19;i>=0;i--){
	if(a+(1<<i)<=n && b+(1<<i)<=n && rnk[i][a]==rnk[i][b])
	    a+=(1<<i),b+=(1<<i),ans+=(1<<i);
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    string s;cin>>n>>s;
    for(int i=0;i<n;i++){
	sm[i]=(i==0?0:sm[i-1])+(s[i]=='('?1:-1);
    }
    sm[n]=-inf;
    for(int i=n-1;i>=0;i--){
	nxt[i]=i+1;
	while(sm[nxt[i]]>=sm[i])
	    nxt[i]=nxt[nxt[i]];
    }
    for(int i=n;i>=0;i--){
	if(i>=n-1 || s[i]==')' || nxt[i]==n) sp[0][i]=n;
	else sp[0][i]=nxt[i]+1,cnt[i]=1+cnt[sp[0][i]];
	for(int j=1;j<20;j++)
	    sp[j][i]=sp[j-1][sp[j-1][i]];
    }
    for(int i=0;i<n;i++){
	rnk[0][i]=s[i]=='('?0:1;
    }
    for(int i=1;i<20;i++){
	for(int j=0;j<n;j++)
	    p[j]={{rnk[i-1][j],j+(1<<(i-1))<n?rnk[i-1][j+(1<<(i-1))]:-1},j};
	sort(p,p+n);
	for(int j=1;j<n;j++)
	    rnk[i][p[j].S]=rnk[i][p[j-1].S]+(p[j-1].F!=p[j].F);
    }
    ll ans=0;
    for(int i=0;i<n;i++){
	if(s[p[i].S]==')') continue;
	int bf=(i==0?0:LCP(p[i-1].S,p[i].S));
	int pos=p[i].S;
	for(int j=19;j>=0;j--){
	    if(sp[j][pos]-pos<=bf)
		bf-=sp[j][pos]-pos,pos=sp[j][pos];
	}
	ans+=cnt[pos];
    }
    return cout<<ans<<endl,0;
}