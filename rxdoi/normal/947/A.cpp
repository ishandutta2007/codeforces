#include<bits/stdc++.h>

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

const int top=1e6;
const int N=top+19;

int pri[N],vis[N],mnp[N],f[N];
int ans,n,l,res;

void Init(){
	For(i,2,top+1){
		if (!vis[i]){
			pri[++*pri]=i;
			mnp[i]=i;
		}
		for (int j=1;j<=*pri&&pri[j]*i<=top;j++){
			vis[pri[j]*i]=1;
			mnp[pri[j]*i]=pri[j];
			if (i%pri[j]==0) break;
		}
	}
}

int main(){
	Init();
	n=IN();
	f[1]=1;
	For(i,2,top+1){
		f[i]=i;
		for (int x=i;x!=1;x/=mnp[x]){
			f[i]=min(f[i],max(i-mnp[x],mnp[x])+1);
		}
	}
	l=n;
	for (int x=n;x!=1;x/=mnp[x]) l=min(l,max(n-mnp[x],mnp[x])+1);
	res=n;
	For(i,l,n+1) res=min(res,f[i]);
	printf("%d\n",res);
}