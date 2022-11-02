#include<bits/stdc++.h>

using namespace std;



int main(){

	int n,a;

	long long sum=0;

	cin>>n;

	for(int i=1;i<=n;i++){

		scanf("%d",&a);

		sum+=a;

	}

	if(sum%n) printf("%d\n",n-1);

	else printf("%d",n);

}