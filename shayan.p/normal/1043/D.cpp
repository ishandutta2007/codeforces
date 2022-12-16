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

const int maxn=1e5+10,mod=1e9+7,P1=911382323,P2=972663749;

int a[11][maxn],pos[11][maxn];
pii hsh[11][maxn];
int tn0[maxn],tn1[maxn];

pii Hash(int id,int l,int r){
    int A=(1ll*hsh[id][r].F-1ll*hsh[id][l].F*tn0[r-l])%mod;
    int B=(1ll*hsh[id][r].S-1ll*hsh[id][l].S*tn1[r-l])%mod;
    if(A<0)A+=mod;
    if(B<0)B+=mod;
    return {A,B};
}

int main(){
    int n,m;scanf("%d%d",&n,&m);
    tn0[0]=tn1[0]=1;
    for(int i=1;i<maxn;i++){
	tn0[i]=1ll*tn0[i-1]*P1 %mod;
	tn1[i]=1ll*tn1[i-1]*P2 %mod;
    }
    for(int i=0;i<m;i++){
	for(int j=1;j<=n;j++){
	    scanf("%d",&a[i][j]);
	    pos[i][a[i][j]]=j;
	    hsh[i][j].F=(1ll*hsh[i][j-1].F*P1+a[i][j])%mod;
	    hsh[i][j].S=(1ll*hsh[i][j-1].S*P2+a[i][j])%mod;
	}
    }
    ll ans=0;
    int ln=0;
    for(int i=1;i<=n;i++){
	ln++;
	while(ln>0){
	    bool is=0;
	    for(int j=1;j<m;j++){
		int ps=pos[j][a[0][i]];
		is|=Hash(0,i-ln,i)!=Hash(j,ps-ln,ps);
	    }
	    if(!is)break;
	    ln--;
	}
	ans+=ln;
    }
    printf("%lld\n",ans);
    return 0;
}