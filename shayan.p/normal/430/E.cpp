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

const int maxn=25,MASK=(1<<12)+10;

int a[maxn],CNT;
bool dp[MASK][maxn];

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    int N,n=0,mx=0;cin>>N;
    for(int i=0;i<N;i++){
	int x;cin>>x;
	if(x==1) CNT++;
	else a[n++]=x;
	if(x==2) return cout<<"NO\n",0;
	mx=max(mx,x);
    }
    if(CNT<=n || mx!=N) return cout<<"NO\n",0;
    for(int i=0;i<=CNT;i++) dp[0][i]=1;
    for(int msk=1;msk<(1<<n);msk++){
	int id=-1,id2=-1,C=__builtin_popcount(msk);
	for(int i=0;i<n;i++){
	    if(bit(msk,i) && (id==-1 || a[id]<a[i]))
		id=i;
	}
	for(int i=0;i<n;i++){
	    if(bit(msk,i) && (id2==-1 || a[id2]<a[i]) && id!=i)
		id2=i;
	}
	for(int i=1;i<=CNT;i++){
	    dp[msk][i]=(a[id]==C+i && (id2==-1 || a[id]!=a[id2]+1) && dp[msk ^ (1<<id)][i])||(dp[msk][i-1]);
	    for(int j=1;j<i;j++){
		int msk2=msk;
		while(true){
		    msk2=(msk2-1)&msk;
		    if(msk2==0) break;
		    dp[msk][i]|=dp[msk2][j] && dp[msk^msk2][i-j];
		}
	    }
	}
    }
    return cout<<(dp[(1<<n)-1][CNT]?"YES":"NO")<<endl,0;
}