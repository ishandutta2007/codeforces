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

const int maxn=1e5+10,SQ=75;

int lst[maxn],sm[maxn],ans[maxn],a[maxn],pt;
int dp[2][maxn],cnt[maxn],CNT;

void add(int id,int x){
    ++id;
    while(id<maxn)
	sm[id]+=x,id+=(id & -id);
}
int ask(int id){
    ++id;
    int ans=0;
    while(id>0)
	ans+=sm[id],id-=(id & -id);
    return ans;
}

int arr[maxn],CC;
void restart(){
    for(int i=0;i<CC;i++)
	cnt[arr[i]]=0;
    CC=0;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n;cin>>n;
    for(int i=0;i<n;i++){
	cin>>a[i];
    }
    memset(lst,-1,sizeof lst);
    for(int i=0;i<n;i++){
	if(lst[a[i]]==-1)
	    lst[a[i]]=i,CNT++;
	dp[1][i]=CNT;
    }
    pt=n+1;
    for(int i=2;i<min(n,SQ);i++){
	bool o=i&1;
	for(int j=dp[!o][n-1];j<pt;j++)
	    ans[j]=i-1;
	pt=min(pt,dp[!o][n-1]);
	memset(lst,-1,sizeof lst);
	memset(sm,0,sizeof sm);
	int pos=i-1;
	for(int j=i-1;j<n;j++){
	    if(lst[a[j]]==-1){
		lst[a[j]]=j;
	    }
	    else{
		add(lst[a[j]],-1);
		lst[a[j]]=j;
	    }
	    add(lst[a[j]],1);
	    int S=ask(j);
	    while(dp[!o][pos-1]<(S-ask(pos-1)))
		pos++;
	    dp[o][j]=dp[!o][pos-1];
	}
    }
    
    for(int i=1;i<pt;i++){
	restart();
	CNT=0;
	for(int j=0;j<n;j++){
	    CNT+=(++cnt[a[j]])==1;
	    arr[CC++]=a[j];
	    if(CNT>i) CNT=1,restart(),cnt[a[j]]=1,++ans[i],arr[CC++]=a[j];
	}
	++ans[i];
    }
    for(int i=1;i<=n;i++)
	cout<<ans[i]<<" ";
    cout<<endl;
    return 0;
}