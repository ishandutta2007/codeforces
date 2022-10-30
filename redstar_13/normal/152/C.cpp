#include<bits/stdc++.h>

#define mod 1000000007



using namespace std;



int main(){

	

//	freopen("in.txt","r",stdin);

	char name[105][105];

	int n,num[256],m;

	int a='A',z='Z';

	long long ans=1;	

	cin>>n>>m;

	

	for(int i=1;i<=n;i++) scanf("%s",name[i]);

	for(int i=0;i<m;i++){

		int cnt=0;

		memset(num,0,sizeof(num));

		for(int j=1;j<=n;j++) {

			num[name[j][i]]++;

		}

		for(int k=a;k<=z;k++)

			if(num[k]) cnt++;

		ans=ans*cnt%mod;

	}

	printf("%d",ans);

	return 0;



}