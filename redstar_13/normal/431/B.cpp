#include<bits/stdc++.h>



using namespace std;

int ha[6][6],p[6],k[5];

int main(){

//	freopen("in.txt","r",stdin);

	int ans=0;



	for(int i=1;i<=5;i++)	for(int j=1;j<=5;j++)	scanf("%d",&ha[i][j]);	

	for(int i=1;i<=5;i++) p[i]=i;

	

	do{

		for(int i=1;i<=4;i++)

		k[i]=ha[p[i]][p[i+1]]+ha[p[i+1]][p[i]];

		ans=max(ans,k[1]+k[2]+2*k[3]+2*k[4]);

	}while(next_permutation(p+1,p+6));

	printf("%d",ans);

	return 0;

}