#include<bits/stdc++.h>

using namespace std;



int main(){

	int n,x,a,sum=0;

	cin>>n>>x;

	for(int i=0;i<n;i++) { scanf("%d",&a); sum+=a; }

	sum=abs(sum);

	int ans=sum/x;

	if(sum%x) ans++;

	printf("%d",ans);



}