// High above the clouds there is a rainbow...

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

const int maxn=255,Mask=(1<<16),mod=1e9+7;
const ll inf=1e18;

string s[maxn];
bool state[maxn][maxn];
int dp[maxn][Mask+10][2][2];

void add(int &a,int &b){
    a+=b;
    while(a>=mod) a-=mod;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n,m;cin>>n>>m;
    for(int i=0;i<n;i++){
	cin>>s[i];
    }
    if(n<=m){
	for(int i=0;i<n;i++)
	    for(int j=0;j<m;j++)
		state[i][j]= s[i][j]=='x';
    }
    else{
	for(int i=0;i<n;i++)
	    for(int j=0;j<m;j++)
		state[j][i]= s[i][j]=='x';
	swap(n,m);
    }
    if(state[0][0]){
	dp[0][0][0][0]=1;
    }
    else{
	dp[0][1][1][0]=dp[0][0][0][1]=1;
    }
    for(int i=0;i<n*m-1;i++){
	for(int msk=0;msk<(1<<n);msk++){
	    for(int q=0;q<2;q++){
		for(int w=0;w<2;w++){
		    int id=(i+1)%n;
		    int msk2=msk,qq=q;
		    if(state[id][(i+1)/n] && bit(msk2,id)) msk2^=(1<<id);
		    if(id==0 || state[id][(i+1)/n]) qq=0;
		    
		    if(state[id][(i+1)/n]){
			add( dp[i+1][msk2][qq][w], dp[i][msk][q][w]);
		    }
		    else{
			if(bit(msk,id)==0 && qq==0){
			    if(w==0) add( dp[i+1][msk][qq][1], dp[i][msk][q][w] );
			}
			else{
			    add( dp[i+1][msk][qq][w], dp[i][msk][q][w] );
			}
			msk2|=(1<<id), qq=1;
			add( dp[i+1][msk2][qq][w], dp[i][msk][q][w] );
		    }
		}
	    }
	}
    }
    int ans=0;
    for(int msk=0;msk<(1<<n);msk++){
	for(int q=0;q<2;q++)
	    for(int w=0;w<2;w++)		
		add( ans, dp[n*m-1][msk][q][w] );
    }
    return cout<<ans<<endl,0;
}
// Deathly mistakes:
//  * Read the problem curfully.
//  * Check maxn.
//  * Overflows.