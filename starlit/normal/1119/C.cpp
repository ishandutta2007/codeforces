#include<bits/stdc++.h>
const int N=503;
using namespace std;
int n,m,x,a[N][N];
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	for(int j=1;j<=m;j++)
	scanf("%d",a[i]+j);
	for(int i=1;i<=n;i++)
	for(int j=1;j<=m;j++){
		scanf("%d",&x);
		a[i][j]^=x;
		if(a[i][j]){
			if(i==n||j==m)
			return puts("No"),0;
			a[i][j]^=1,a[i+1][j]^=1;
			a[i][j+1]^=1,a[i+1][j+1]^=1;
		}
	}
	puts("Yes");
}