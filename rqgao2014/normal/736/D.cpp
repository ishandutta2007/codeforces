#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define vi vector<int>
#define sqr(x) ((x)*(x))
#define FF first
#define SS second
#define debug(x) cerr<<#x<<"="<<x<<endl
#define debuge cerr<<"isok"<<endl
using namespace std;

const int N=4005;
int n,m;
bitset<N> a[N];
pii p[N<<8];

void gauss(){
	for(int i=1;i<=n;i++){
		int t=0;
		for(int j=i;j<=n;j++) 
			if(a[j][i]){t=j;break;}
		if(i!=t) swap(a[i],a[t]);
		for(int j=1;j<i;j++)
			if(a[j][i]) a[j]^=a[i];
		for(int j=i+1;j<=n;j++)
			if(a[j][i]) a[j]^=a[i];
	}
}

int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		int x,y;scanf("%d%d",&x,&y);
		a[x][y]=1;p[i]=mp(x,y);
	}
	for(int i=1;i<=n;i++) a[i][i+n]=1;
	gauss();
	for(int i=1;i<=m;i++)
		if(a[p[i].SS][p[i].FF+n]) puts("NO"); else puts("YES");
	return 0;
}