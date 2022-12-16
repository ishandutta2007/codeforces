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

const int maxn=5e5+10,LG=21,inf=2e9;

int n,dp[maxn];
int rnk[LG][maxn],lcp[LG][maxn],arr[maxn],val[2*maxn],wh[maxn],ID;
string s;

void add(int pos,int x){
    pos+=n;
    val[pos]=x;
    while(pos>1){
	pos>>=1;
	val[pos]=max(val[(pos<<1)],val[(pos<<1)|1]);
    }
}

int ask(int f,int s){
    f+=n,s+=n+1;
    int ans=0;
    while(f<s){
	if(f&1) ans=max(ans,val[f++]);
	if(s&1) ans=max(ans,val[--s]);
	f>>=1;
	s>>=1;
    }
    return ans;
}

inline int LCP(int l,int r){
    int ln=31-__builtin_clz(r-l);
    return min(lcp[ln][l],lcp[ln][r-(1<<ln)]);
}

inline bool CMP(int a,int b){
    if(rnk[ID-1][a]!=rnk[ID-1][b]) return rnk[ID-1][a]<rnk[ID-1][b];
    if(a+(1<<(ID-1))>=n && b+(1<<(ID-1))>=n) return 0;
    if(a+(1<<(ID-1))>=n) return 1;
    if(b+(1<<(ID-1))>=n) return 0;
    return rnk[ID-1][a+(1<<(ID-1))]<rnk[ID-1][b+(1<<(ID-1))];
}

int _LCP(int a,int b){
    int ans=0;
    for(int i=LG-1;i>=0;i--){
	if(a+(1<<i)<=n && b+(1<<i)<=n && rnk[i][a]==rnk[i][b])
	    ans+=(1<<i),a+=(1<<i),b+=(1<<i);
    }
    return ans;
}

void build(){
    for(int i=0;i<n;i++)
	rnk[0][i]=s[i]-'a';
    for(int i=0;i<n;i++)
	arr[i]=i;
    for(ID=1;ID<LG;ID++){
	sort(arr,arr+n,CMP);
	for(int i=1;i<n;i++)
	    rnk[ID][arr[i]]=rnk[ID][arr[i-1]]+CMP(arr[i-1],arr[i]);
    }
    for(int i=0;i<n-1;i++)
	lcp[0][i]=_LCP(arr[i],arr[i+1]);
    for(int i=1;i<LG;i++)
	for(int j=0;j<n;j++)
	    lcp[i][j]=min(lcp[i-1][j],lcp[i-1][j+(1<<(i-1))]);
    for(int i=0;i<n;i++)
	wh[arr[i]]=i;
}

int rangef(int pos,int SZ){
    int l=0,r=pos-1,ans=pos;
    while(l<=r){
	int mid=(l+r)>>1;
	if(LCP(mid,pos)>=SZ)
	    ans=mid,r=mid-1;
	else
	    l=mid+1;
    }
    return ans;
}

int ranges(int pos,int SZ){
    int l=pos+1,r=n-1,ans=pos;
    while(l<=r){
	int mid=(l+r)>>1;
	if(LCP(pos,mid)>=SZ)
	    ans=mid,l=mid+1;
	else
	    r=mid-1;
    }
    return ans;
}

inline void Add(int pos,int SZ){
    add(wh[pos],SZ);
}

inline bool Ask(int pos,int SZ){
    int ff=rangef(wh[pos],SZ),ss=ranges(wh[pos],SZ);
    return ask(ff,ss)>=SZ;
}
/*
int nxt[maxn][26],C=2;

void Addd(int pos,int SZ){
    int tmp=1;
    for(int i=pos;i<pos+SZ;i++){
	if(nxt[tmp][s[i]-'a']==0)
	    nxt[tmp][s[i]-'a']=C++;
	tmp=nxt[tmp][s[i]-'a'];
    }
}

bool Askk(int pos,int SZ){
    int tmp=1;
    for(int i=pos;i<pos+SZ;i++){
	if(nxt[tmp][s[i]-'a']==0) return 0;
	tmp=nxt[tmp][s[i]-'a'];
    }
    return 1;
}
*/

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    
    cin>>n>>s;
    build();
    int ans=1;
    for(int i=n-1;i>=0;i--){
	dp[i]=1+dp[i+1];
	//	if(Askk(i,dp[i]-1)!=Ask(i,dp[i]-1)) exit(0);
	//	if(Askk(i+1,dp[i]-1)!=Ask(i+1,dp[i]-1)) exit(0);
	while(dp[i]>1 && !Ask(i+1,dp[i]-1) && !Ask(i,dp[i]-1)){
	    --dp[i];
	    //	    if(Askk(i,dp[i]-1)!=Ask(i,dp[i]-1)) exit(0);
	    //	    if(Askk(i+1,dp[i]-1)!=Ask(i+1,dp[i]-1)) exit(0);
	    //	    Addd(i+dp[i],dp[i+dp[i]]);
	    Add(i+dp[i],dp[i+dp[i]]);
	}
	ans=max(ans,dp[i]);
    }
    cout<<ans<<endl;
    return 0;
}