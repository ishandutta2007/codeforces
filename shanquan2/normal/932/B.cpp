#include<bits/stdc++.h>
using namespace std;

const int N=1000005;
int a[N],c[10][N];
int main(){
	for(int i=1;i<N;i++){
		if(i<10)a[i]=i;
		else{
			int p=1;
			for(int j=i;j;j/=10)if(j%10)p*=j%10;
			a[i]=a[p];
		}
		for(int j=1;j<10;j++)c[j][i]=c[j][i-1];
		c[a[i]][i]++;
	}
	int q;scanf("%d",&q);
	while(q--){
		int l,r,k;scanf("%d%d%d",&l,&r,&k);
		printf("%d\n",c[k][r]-c[k][l-1]);
	}
	return 0;
}