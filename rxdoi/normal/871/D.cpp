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

const int top=10000000;
const int N=top+19;

int vis[N],pri[N],mu[N],minp[N],sum[N],num[N];
int n;
ll ans,tmp;

void Init(int top){
	mu[1]=1;
	For(i,2,top+1){
		if (!vis[i]){
			pri[++*pri]=i;
			minp[i]=i;
			mu[i]=-1;
		}
		for (int j=1;j<=*pri&&pri[j]*i<=top;j++){
			vis[pri[j]*i]=1;
			minp[pri[j]*i]=pri[j];
			if (i%pri[j]==0){
				mu[pri[j]*i]=0;
				break;
			} else{
				mu[pri[j]*i]=-mu[i];
			}
		}
	}
	For(i,2,top+1) sum[i]=sum[i-1]+(!vis[i]);
}
int cal(int l,int r){
	if (l>r) return 0;
	return sum[r]-sum[l-1];
}

int main(){
	n=IN();
	Init(n);
	For(i,2,n+1) if (!vis[i]){
		ans+=2ll*sum[n/i];
		if (2*i<=n) ans+=3ll*cal(n/i+1,n/2);
	}
	For(i,1,n+1){
		int alb;
		if (i==1) alb=n-1-*pri;
		lf (vis[i]) alb=n/i;
		else alb=n/i-1;
		tmp+=1ll*mu[i]*alb*alb;
	}
	ans+=2*tmp;
	ans+=1ll*(n-1-*pri)*(n-1-*pri)-tmp;
	For(i,2,n+1) if (!vis[i]) ans+=2*(n/i-1);
	For(i,2,n+1) if (vis[i]) num[minp[i]]++;
	For(i,2,n+1) if (num[i]){
		ans+=4ll*num[i]*cal(1,n/i);
		if (2*i<=n) ans+=6ll*num[i]*cal(n/i+1,n/2);
	}
	For(i,2,n+1) if (!vis[i]){
		for (int j=i+i;j<=n;j+=i){
			if (1ll*i*minp[j]<=n) ans-=4;
			lf (2ll*max(i,minp[j])<=n) ans-=6;
		}
	}
	For(i,2,n+1) if (!vis[i]){
		if (1ll*i*i<=n) ans-=2;
		lf (2ll*i<=n) ans-=3;
	} else ans--;
	ans/=2;
	cout<<ans<<endl;
}