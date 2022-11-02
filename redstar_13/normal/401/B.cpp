#include<bits/stdc++.h>



using namespace std;

int vis[5000];



int main(){

//	freopen("in.txt","r",stdin);

	int x,k,n,m,flag;

	cin>>x>>k;

	int mx=x-1,mn=0;



	for(int i=1;i<=k;i++) {

		scanf("%d",&flag);

		if(flag==1) { scanf("%d %d",&n,&m); mx-=2; vis[n]=1; vis[m]=1;}

		else { scanf("%d",&n); mx-=1; vis[n]=1;}

	}



	for(int i=1;i<x;){ 

		if(vis[i]) {i+=1;	continue; }

		if(!vis[i]) { mn++,i+=2;	continue;}

 	}

 	printf("%d %d",mn,mx);

	return 0;

}