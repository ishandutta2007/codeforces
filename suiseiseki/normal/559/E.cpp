#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int Maxn=100;
const int Inf=0x3f3f3f3f;
int n;
struct Node{
	int a,l;
	friend bool operator <(Node a,Node b){
		return a.a<b.a;
	}
}a[Maxn+5];
int f[Maxn+5][Maxn+5][2];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d%d",&a[i].a,&a[i].l);
	}
	sort(a+1,a+1+n);
	memset(f,-0x3f,sizeof f);
	a[0].a=-Inf;
	a[0].l=0;
	f[0][0][0]=0;
	int ans=-Inf;
	for(int i=0;i<n;i++){
		for(int j=0;j<=i;j++){
			for(int k=0;k<2;k++){
				ans=max(ans,f[i][j][k]);
				int right=a[j].a+k*a[j].l;
				int maxn=-Inf,x,y;
				for(int p=i+1;p<=n;p++){
					for(int q=0;q<2;q++){
						int tmp=a[p].a+q*a[p].l;
						if(tmp>maxn){
							maxn=tmp;
							x=p;
							y=q;
						}
						f[p][x][y]=max(f[p][x][y],f[i][j][k]+min(a[p].l,tmp-right)+maxn-tmp);
					}
				}
			}
		}
	}
	for(int i=0;i<=n;i++){
		ans=max(ans,f[n][i][0]);
		ans=max(ans,f[n][i][1]);
	}
	printf("%d\n",ans);
	return 0;
}