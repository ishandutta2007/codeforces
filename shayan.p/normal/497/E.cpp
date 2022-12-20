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

const int maxk=31,mod=1e9+7;

ll n;
int k;

int Pow(int a,int b){
    int ans=1;
    while(b){
	if(b&1) ans=1ll*ans*a %mod;
	a=1ll*a*a %mod;
	b>>=1;
    }
    return ans;
}

struct matrice{
    vector<vector<int> >v;
    matrice(int st=0){
	v.resize(maxk);
	for(int i=0;i<maxk;i++){
	    v[i].resize(maxk);
	    v[i][i]=st;
	}
    }
};

matrice inv(matrice a){
    matrice b(1);
    for(int i=0;i<=k;i++){
	for(int j=i;j<=k;j++){
	    if(a.v[j][i]!=0){
		swap(a.v[i],a.v[j]);
		swap(b.v[i],b.v[j]);
		break;
	    }
	}
	int INV=Pow(a.v[i][i],mod-2);
	for(int j=0;j<=k;j++){
	    a.v[i][j]=1ll*a.v[i][j]*INV %mod;
	    b.v[i][j]=1ll*b.v[i][j]*INV %mod;
	}
	for(int j=0;j<=k;j++){
	    if(j==i) continue;
	    if(a.v[j][i]!=0){
		int cof=a.v[j][i];
		for(int w=0;w<=k;w++){
		    a.v[j][w]=(1ll*a.v[j][w]-1ll*cof*a.v[i][w])%mod;
		    b.v[j][w]=(1ll*b.v[j][w]-1ll*cof*b.v[i][w])%mod;
		}
	    }
	}
    }
    return b;
}

matrice operator*(matrice a,matrice b){
    matrice c;
    for(int i=0;i<=k;i++)
	for(int j=0;j<=k;j++)
	    for(int w=0;w<=k;w++)
		c.v[i][j]=(1ll*c.v[i][j]+1ll*a.v[i][w]*b.v[w][j])%mod;
    return c;
}

int f(ll n){
    int ans=0;
    while(n>0){
	ans+=n%k;
	n/=k;
    }
    return ans;
}

matrice trans[maxk];
matrice ntrans[maxk];

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    
    cin>>n>>k;

    for(int i=0;i<k;i++){
	for(int j=0;j<=k;j++)
	    trans[i].v[j][j]=1;
	trans[i].v[i][i]=0;
	trans[i].v[k][i]=1;
	trans[i].v[k][k]=2;
	trans[i].v[i][k]=-1;
    }
    matrice ans(1);    
    while(n>0){
	int sm=f(n-1);
	for(int i=(n%k)-1;i>=0;i--,sm--)
	    ans=trans[sm%k]*ans;
	matrice tmp(1);
	for(int i=0;i<k;i++)
	    tmp=tmp*trans[i];
	for(int i=0;i<k;i++){
	    ntrans[i]=tmp;
	    tmp=inv(trans[i])*tmp;
	    tmp=tmp*trans[i];
	}
	for(int i=0;i<k;i++)
	    trans[i]=ntrans[i];
	n/=k;
    }
    if(ans.v[k][k]<0) ans.v[k][k]+=mod;
    cout<<ans.v[k][k]<<endl;
    return 0;
}