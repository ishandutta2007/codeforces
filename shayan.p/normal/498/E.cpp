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

const int MAX=128,mod=1e9+7;

int a[MAX][MAX],tmp[MAX][MAX],tmp2[MAX][MAX],tmp3[MAX],ans[MAX];
int tw;

void M1(int a[][MAX]){
    for(int i=0;i<tw;i++)
	for(int j=0;j<tw;j++)
	    a[i][j]=(i==j);
}

void Mul(int *a,int b[][MAX]){
    memset(tmp3,0,sizeof tmp3);
    for(int i=0;i<tw;i++)
	for(int j=0;j<tw;j++)
	    tmp3[i]=(tmp3[i]+1ll*b[i][j]*a[j])%mod;
    for(int i=0;i<tw;i++)
	a[i]=tmp3[i];
}

void Mul(int a[][MAX],int b[][MAX]){
    memset(tmp2,0,sizeof tmp2);
    for(int i=0;i<tw;i++)
	for(int j=0;j<tw;j++)
	    for(int k=0;k<tw;k++)
		tmp2[i][j]=(tmp2[i][j]+1ll*a[i][k]*b[k][j])%mod;
    for(int i=0;i<tw;i++)
	for(int j=0;j<tw;j++)
	    a[i][j]=tmp2[i][j];
}
void Pow(int a[][MAX],int b){
    M1(tmp);
    for(int i=0;i<tw;i++)
	tmp[i][i]=1;
    while(b){
	if(b&1) Mul(tmp,a);
	Mul(a,a);
	b/=2;
    }
    for(int i=0;i<tw;i++)
	for(int j=0;j<tw;j++)
	    a[i][j]=tmp[i][j];
}

int main(){
    ans[0]=1;
    for(int q=1;q<=7;q++){
	tw=(1<<q);
	for(int i=0;i<MAX;i++)
	    tmp3[i]=ans[i];
	memset(ans,0,sizeof ans);
	for(int i=0;i<tw;i++)
	    ans[i+(tw/2)]=tmp3[i];
	int x;cin>>x;
	for(int i=0;i<tw;i++){
	    for(int j=0;j<tw;j++){
		int cnt=0;
		for(int k=0;k<(tw/2);k++){
		    int K=1|(k<<1)|tw;
		    bool yes=1;
		    for(int w=0;w<tw;w++)
			if(bit(i,w) && bit(j,w) && bit(K,w) && bit(K,w+1))
			    yes=0;
		    cnt+=yes;
		}
		a[i][j]=cnt;
	    }
	}
	Pow(a,x);
	Mul(ans,a);
    }
    cout<<ans[127]<<endl;
    return 0;
}