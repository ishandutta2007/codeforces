#include<bits/stdc++.h>



using namespace std;



int main(){

	int n,k;

	cin>>n>>k;

	for(int i=1;i<=n;i++)

	if(i<=k)	printf("%d ",n-i+1);

	else printf("%d ",i-k);

	return 0;

}