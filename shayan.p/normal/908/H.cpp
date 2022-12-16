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

const int maxn=50,MASK=1<<24,mod=1e9+7;

int comp[maxn],g[maxn],arr[MASK],arr2[MASK],cnt,n,C;
string s[maxn];

void dfs(int u){
    comp[u]=C,cnt++;
    for(int i=0;i<n;i++){
	if(comp[i]!=C && s[u][i]=='A')
	    dfs(i);
    }
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    cin>>n;
    for(int i=0;i<n;i++){
	cin>>s[i];
    }
    for(int i=0;i<n;i++){
	if(comp[i]==0){
	    cnt=0,++C,dfs(i);
	    if(cnt==1) comp[i]=-1,--C;
	}
    }
    for(int i=0;i<n;i++){
	for(int j=0;j<n;j++){
	    if(comp[i]!=-1 && comp[i]==comp[j] && s[i][j]=='X') return cout<<-1<<endl,0;
	    if(s[i][j]=='X' && comp[i]!=-1 && comp[j]!=-1) g[comp[i]-1]|=(1ll<<(comp[j]-1));
	}
    }
    for(int i=0;i<C;i++){
	g[i]=(1<<C)-1-g[i];
    }
    arr[0]=1;
    for(int msk=1;msk<(1<<C);msk++){
	int ctz=__builtin_ctz(msk);
	arr[msk]= arr[msk ^ (1<<ctz)] && ((msk ^ (1<<ctz)) & g[ctz]) == (msk ^ (1<<ctz)) ;
    }
    for(int i=0;i<C;i++){
	for(int msk=0;msk<(1<<C);msk++){
	    if(bit(msk,i)) arr[msk]+=arr[msk ^ (1<<i)];
	}
    }
    for(int i=0;i<(1<<C);i++){
	arr2[i]=1;
    }
    for(int i=0;i<=C;i++){
	int num=0;
	for(int msk=0;msk<(1<<C);msk++){
	    num=(num+arr2[msk]*( __builtin_popcount(msk) & 1 ? -1 : 1) )%mod;
	}
	if(num%mod!=0) return cout<<n-1+i<<endl,0;
	for(int msk=0;msk<(1<<C);msk++){
	    arr2[msk]=1ll*arr2[msk]*arr[msk] %mod;
	}
    }
    return 0;
}
// Deathly mistakes:
//  * Read the problem curfully.
//  * Check maxn.
//  * Overflows.