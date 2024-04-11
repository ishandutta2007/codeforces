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

const int maxn=3e5+10,Max=1e7+10;

vector<pii>v[maxn];
int H[Max],id1[Max],id2[Max];
ll C[Max],dp[2][Max];

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n,m;cin>>n>>m;
    for(int i=0;i<n;i++){
	int SZ;cin>>SZ;
	v[i].resize(SZ);
	for(int j=0;j<SZ;j++)
	    cin>>v[i][j].F;
	for(int j=0;j<SZ;j++)
	    cin>>v[i][j].S;
    }
    int q;cin>>q;
    int S=0;
    while(q--){
	int a,b;cin>>a>>b;
	for(pii p:v[--a])
	    H[S]=p.F,C[S]=1ll*p.S*b,S++;
    }
    stack<int>st;
    for(int i=0;i<m;i++){
	id1[i]=-1;
	while(sz(st)){
	    int num=st.top();
	    if(id1[i]==-1 && num+H[num]>i) id1[i]=num;
	    if(num+H[num]>i+H[i]) break;
	    st.pop();
	}
	st.push(i);
    }
    while(sz(st)){
	st.pop();
    }
    for(int i=0;i<m;i++){
	id2[i]=i;
	while(sz(st) && i-st.top()<H[i]) id2[i]=id2[st.top()],st.pop();
	st.push(i);
    }
    dp[0][0]=dp[1][0]=C[0];
    for(int i=1;i<m;i++){
	dp[1][i]=dp[0][i-1]+C[i];
	if(id1[i]!=-1) dp[1][i]=min(dp[1][i],dp[1][id1[i]]);
	dp[0][i]=min(dp[1][i],C[i]+(id2[i]==0?0:dp[0][id2[i]-1]));
    }
    return cout<<dp[0][m-1]<<endl,0;
}