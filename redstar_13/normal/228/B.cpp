#include<bits/stdc++.h>



using namespace std;

pair<int ,int> ans;

int a[100][100],b[100][100];

char stra[100][100],strb[100][100];

int main(){

//	freopen("in.txt","r",stdin);

	int na,ma,nb,mb;

	cin>>na>>ma;

	for(int i=1;i<=na;i++){

		scanf("%s",stra[i]);

		for(int j=1;j<=ma;j++) a[i][j]=stra[i][j-1]-'0';

	}

	cin>>nb>>mb;

	for(int i=1;i<=nb;i++){

		scanf("%s",strb[i]);

		for(int j=1;j<=mb;j++) b[i][j]=strb[i][j-1]-'0';

	}

	int i,j,mx=0;

	ma=max(ma,mb);

	na=max(na,nb);

	for(i=-na;i<=na;i++){

		for(j=-ma;j<=ma;j++){

			int sum=0;

			for(int m=1;m<=na;m++)

			for(int n=1;n<=ma;n++)

			if(a[m][n]&&m+i>=1&&n+j>=1&&m+i<=nb&&n+j<=mb&&b[m+i][n+j]) sum++;

			if(sum>mx) mx=sum,ans.first=i,ans.second=j;

		}

	}

	printf("%d %d\n",ans.first,ans.second);

	return 0;

}