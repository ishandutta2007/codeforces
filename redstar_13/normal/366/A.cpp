#include<bits/stdc++.h>

#define x first

#define y second

using namespace std; 



int main(){

//	freopen("in.txt","r",stdin);

	int n,a,b,c,d;

	cin>>n;

	

	for(int i=1;i<=4;i++){

		scanf("%d%d%d%d",&a,&b,&c,&d);

		if(a+c<=n) { printf("%d %d %d",i,a,n-a); return 0; }

		if(a+d<=n) { printf("%d %d %d",i,a,n-a); return 0; }

		if(b+c<=n) { printf("%d %d %d",i,b,n-b); return 0; }

		if(b+d<=n) { printf("%d %d %d",i,b,n-b); return 0; }

	}

	printf("-1");

	return 0;

}