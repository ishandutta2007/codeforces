#include<bits/stdc++.h>



using namespace std;



int main(){

//	freopen("in.txt", "r",stdin);

	int n,m;

	char a[105][105];

	int num[105][105];

	cin>>n>>m;

	for(int i=1;i<=n;i++) scanf("%s",a[i]);

	for(int i=1;i<=n;i++)

	for(int j=0;j<m;j++)	num[i][j]=a[i][j]-'0';

	int ans=0;

	for(int i=1;i<=n;i++){

		for(int k=0;k<m;k++){

			int p=0;

			for(int j=1;j<=n;j++)

			if(num[j][k]<=num[i][k]) p++;

			if(p==n) {ans++; break;}

		}

	}

	printf("%d",ans);

	return 0;

}