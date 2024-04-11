// Can U hack it?

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

const int maxH=33,maxN=1010,mod=7340033,TW=4096,W=6111633,RVT=7338241;

int dp[maxH][maxN],cnt[TW+10],tmp1[TW+10],tmp2[TW+10],w[TW+10];

int hh(int num){
    int cnt=0;
    while(num&1 && num>1){
	num/=2;
	cnt++;
    }
    return cnt;
}

void pre(){
    w[0]=1;
    for(int i=1;i<=TW;i++)// ======
	w[i]=(1ll*W*w[i-1])%mod;
}

void transform(int *a,bool rev){
    for(int ln=1;ln<TW;ln*=2){
	int step=TW/(2*ln);
	for(int st=0;st<step;st++){
	    for(int i=0;i<ln;i++){
		tmp1[i]=a[st+2*i*step];
		tmp2[i]=a[st+2*i*step+step];
	    }
	    for(int i=0;i<ln;i++){
		int A=tmp1[i],B=(1ll*tmp2[i]*w[(rev?-1:1)*step*i+(rev?TW:0)])%mod;
		a[st+i*step]=(A+B)%mod;
		a[st+(i+ln)*step]=(A-B+mod)%mod;
	    }
	}
    }
    if(rev){
	for(int i=0;i<TW;i++)
	    a[i]=(1ll*a[i]*RVT)%mod;
    }
}

int tavan(int a,int b){
    int ans=1;
    while(b){
	if(b&1) ans=(1ll*ans*a)%mod;
	a=(1ll*a*a)%mod;
	b/=2;
    }
    return ans;
}

int main(){
    pre();
    dp[0][0]=1;
    for(int i=1;i<maxH;i++){
	memset(cnt,0,sizeof cnt);
	for(int j=0;j<maxN;j++)
	    cnt[j]=dp[i-1][j];
	transform(cnt,0);
	for(int i=0;i<TW;i++){
	    cnt[i]=(1ll*cnt[i]*cnt[i])%mod;
	    cnt[i]=(1ll*cnt[i]*cnt[i])%mod;
	}
	transform(cnt,1);
	dp[i][0]=1;
	for(int j=1;j<maxN;j++)
	    dp[i][j]=cnt[j-1];
    }
    int q;scanf("%d",&q);
    while(q--){
	int n,k;scanf("%d%d",&n,&k);
	printf("%d\n",dp[hh(n)][k]);
    }
}