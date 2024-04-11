#include<bits/stdc++.h>



#define NN 100011

using namespace std;

typedef long long INT;

typedef double DO;



int a[NN];



int main(){

	int n,i,j,k;

	cin>>n>>k;

	for(i=1; i<=n; i++){

		scanf("%d", a+i);

	}	

	for(i=k; i<=n; i++){

		if(a[i]!=a[k]) {puts("-1");return 0;}

	}

	int ans=0;

	for(i=1; i<k; i++) {

		if(a[i]!=a[k]) ans=i;

	}

	cout<<ans<<endl; 

	

	

	return 0;

}