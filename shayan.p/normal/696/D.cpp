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

const int maxn=210,mod=1e9+7;
const ll inf=5e18;

int a[maxn],val[maxn];
int nxt[maxn][26],f[maxn],C;

struct matrice{
    ll a[maxn][maxn];
    matrice(){
	build();
    }
    void build(){
	for(int i=0;i<maxn;i++)
	    for(int j=0;j<maxn;j++)
		a[i][j]=-inf;
	for(int i=0;i<maxn;i++)
	    a[i][i]=0;
    }
    ll* operator[](int i){
	return a[i];
    }
};matrice tmp;

matrice operator * (matrice a,matrice b){
    for(int i=0;i<maxn;i++){
	for(int j=0;j<maxn;j++){
	    ll num=-inf;
	    for(int k=0;k<maxn;k++){
		if(a[i][k]==-inf || b[k][j]==-inf) continue;
		num=max(num,a[i][k]+b[k][j]);
	    }
	    tmp[i][j]=num;
	}
    }
    return tmp;
}

matrice operator ^ (matrice a,ll n){
    matrice ans;
    while(n){
	if(n&1) ans=ans*a;
	a=a*a;
	n>>=1;
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n;ll l;cin>>n>>l;
    for(int i=0;i<n;i++){
	cin>>a[i];
    }
    for(int i=0;i<n;i++){
	string s;cin>>s;
	int tmp=0;
	for(char ch:s){
	    if(nxt[tmp][ch-'a']==0)
		nxt[tmp][ch-'a']=++C;
	    tmp=nxt[tmp][ch-'a'];
	}
	val[tmp]+=a[i];
    }
    queue<int> q;
    for(int i=0;i<26;i++){
	if(nxt[0][i]!=0)
	    q.push(nxt[0][i]);
    }
    while(sz(q)){
	int u=q.front();q.pop();
	val[u]+=val[f[u]];
	for(int i=0;i<26;i++){
	    if(nxt[u][i]==0)
		nxt[u][i]=nxt[f[u]][i];
	    else
		f[nxt[u][i]]=nxt[f[u]][i],q.push(nxt[u][i]);
	}
    }
    matrice mat;
    for(int i=0;i<=C;i++){
	for(int j=0;j<26;j++){
	    mat[i][nxt[i][j]]=val[nxt[i][j]];
	}
    }
    mat=mat ^ l;
    ll ans=0;
    for(int i=0;i<=C;i++){
	ans=max(ans,mat[0][i]);
    }
    return cout<<ans<<endl,0;
}