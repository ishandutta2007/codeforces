#include<bits/stdc++.h>]



using namespace std;



int main(){

	int x,y,a,b,ans=0;

	cin>>x>>y>>a>>b;

	for(int m=b;m<=min(x,y);m++){

		if(m<a) ans+=x-a+1;

		else ans+=x-m;

	}	



	printf("%d\n",ans);

	for(int i=a;i<=x;i++)

	for(int j=b;j<=y;j++)

		if(i>j) printf("%d %d\n",i,j);

	return 0;

}