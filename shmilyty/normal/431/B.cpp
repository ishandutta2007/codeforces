#include<bits/stdc++.h>
using namespace std;
int g[6][6],ans;
int main()
{
	for(int i=1;i<=5;i++)
		for(int l=1;l<=5;l++)
			cin>>g[i][l];
	int a[5]={1,2,3,4,5};
	ans=g[1][2]+g[2][1]+g[3][4]+g[4][3]+g[2][3]+g[3][2]+g[4][5]+g[5][4]+g[3][4]+g[4][3]+g[4][5]+g[5][4];
	do{
		ans=max(ans,g[a[0]][a[1]]+g[a[1]][a[0]]+g[a[2]][a[3]]+g[a[3]][a[2]]+g[a[1]][a[2]]+g[a[2]][a[1]]+g[a[3]][a[4]]+g[a[4]][a[3]]+g[a[2]][a[3]]+g[a[3]][a[2]]+g[a[3]][a[4]]+g[a[4]][a[3]]);
	}while(next_permutation(a,a+5));
	cout<<ans;
	return 0;
}