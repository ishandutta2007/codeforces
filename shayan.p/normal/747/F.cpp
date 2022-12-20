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

const int maxd=165;

int n,k,ans[maxd],cnt[16];
ll dp[maxd],tmp[maxd],C[maxd][maxd];

void build(){
    dp[0]=C[0][0]=1;
    for(int i=1;i<maxd;i++){
	C[i][0]=C[i][i]=1;
	for(int j=1;j<i;j++)
	    C[i][j]=C[i-1][j]+C[i-1][j-1];
    }
    for(int i=0;i<16;i++){
	cnt[i]=k;
	memset(tmp,0,sizeof tmp);
	for(int j=0;j<maxd;j++)
	    for(int w=0;w<=cnt[i] && j+w<maxd;w++)
		tmp[j+w]+=dp[j]*C[j+w][w];
	for(int j=0;j<maxd;j++)
	    dp[j]=tmp[j];
    }
}

void Add(int x,int y){
    cnt[x]+=y;
    memset(dp,0,sizeof dp);
    dp[0]=1;
    for(int i=0;i<16;i++){
	memset(tmp,0,sizeof tmp);
	for(int j=0;j<maxd;j++)
	    for(int w=0;w<=cnt[i] && j+w<maxd;w++)
		tmp[j+w]+=dp[j]*C[j+w][w];
	for(int j=0;j<maxd;j++)
	    dp[j]=tmp[j];
    }
}

ll Ask(ll ln){
    return dp[ln];
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);    
    cin>>n>>k;
    build();
    int dig=1,st=1;
    for(dig=1;dig<=16*k;dig++){
	ll num=0;
	for(st=1;st<16;st++){
	    if(cnt[st]==0) continue;
	    Add(st,-1);
	    num=Ask(dig-1);
	    if(num>=n) goto Out;
	    n-=num;
	    Add(st,1);
	}
    }
 Out:;
    ans[dig]=st;
    int ln=dig;
    for(--dig;dig>=1;--dig){
	for(ans[dig]=0;ans[dig]<16;ans[dig]++){
	    if(cnt[ans[dig]]==0) continue;
	    Add(ans[dig],-1);
	    ll num=Ask(dig-1);
	    if(num>=n) break;
	    n-=num;
	    Add(ans[dig],1);
	}
    }
    for(;ln>=1;ln--){
	if(ans[ln]<10) cout<<ans[ln];
	else cout<<char('a'+ans[ln]-10);
    }
    cout<<endl;
    return 0;
}