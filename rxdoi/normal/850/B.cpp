#include<set>
#include<map>
#include<cmath>
#include<queue>
#include<bitset>
#include<string>
#include<cstdio>
#include<cctype>
#include<cassert>
#include<cstdlib>
#include<cstring>
#include<sstream>
#include<iostream>
#include<algorithm>

#define For(i,x,y) for (int i=x;i<y;i++)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define lf else if

#define dprintf(...) fprintf(stderr,__VA_ARGS__)
using namespace std;

typedef long long ll;
typedef double db;
typedef pair<int,int> pii;
typedef vector<int> Vi;

int IN(){
	int c,f,x;
	while (!isdigit(c=getchar())&&c!='-');c=='-'?(f=1,x=0):(f=0,x=c-'0');
	while (isdigit(c=getchar())) x=(x<<1)+(x<<3)+c-'0';return !f?x:-x;
}

const int top=2e6;
const int N=top+19;
const ll oo=1ll<<60;

int mu[N],vis[N],pri[N],A[N];
int n,x,y,lim;
ll B[N];
ll mn=oo;

void Init(){
	mu[1]=1;
	For(i,2,top+1){
		if (!vis[i]){
			pri[++*pri]=i;
			mu[i]=-1;
		}
		for (int j=1;j<=*pri&&pri[j]*i<=top;j++){
			vis[pri[j]*i]=0;
			if (i%pri[j]==0){
				mu[pri[j]*i]=0;
				break;
			} else{
				mu[pri[j]*i]=-mu[i];
			}
		}
	}
}

int main(){
	Init();
	n=IN(),x=IN(),y=IN();
	For(i,1,n+1){
		int w=IN();
		A[w]++;
		B[w]+=w;
	}
	For(i,1,top+1){
		A[i]+=A[i-1];
		B[i]+=B[i-1];
	}
	For(i,2,top+1) if (mu[i]){
		ll ans=0;
		int lim=min(x/y,i-1);
		for (int l=1,r;l<=1e6;l=r+1){
			r=l+i-1;
			ans+=1ll*x*(A[r-lim-1]-A[l-1]);
			ans+=1ll*y*(1ll*r*(A[r]-A[r-lim-1])-(B[r]-B[r-lim-1]));
		}
		mn=min(mn,ans);
	}
	cout<<mn<<endl;
}