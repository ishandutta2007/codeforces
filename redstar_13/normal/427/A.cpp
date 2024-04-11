#include<bits/stdc++.h>

using namespace std;



int main(){

	int n,ans=0,a,k=0;

	cin>>n;

	for(int i=1;i<=n;i++) {

		scanf("%d",&a);

		if(a<0) k--;

		if(a>=0) { if(k<0) { ans+=-k;  k=a; }

				else 	k+=a; }  	

	}

	if(k<0) ans+=-k;

	printf("%d",ans);

	return 0;

}