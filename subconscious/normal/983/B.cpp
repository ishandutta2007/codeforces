#include<bits/stdc++.h>
#define rep(i,n) for(int i=1;i<=n;++i)
using namespace std;
typedef long long ll;
const int N=5005;
int a[N],b[N][N],c[N][N];
int q,L,R,n;
int main(){
	scanf("%d",&n);
	rep(i,n)scanf("%d",a+i);
	rep(i,n)b[i][i]=c[i][i]=a[i];
	rep(l,n-1)rep(i,n-l)b[i][i+l]=b[i][i+l-1]^b[i+1][i+l],//,printf("%d %d %d\n",i,i+l,b[i][i+l]),
		c[i][i+l]=max(max(c[i][i+l-1],c[i+1][i+l]),b[i][i+l]);
	scanf("%d",&q);
	rep(i,q){
		scanf("%d%d",&L,&R);
		printf("%d\n",c[L][R]);
	}
	//system("pause");
	return 0;
}