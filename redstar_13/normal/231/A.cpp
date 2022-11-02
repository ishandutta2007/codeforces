#include<bits/stdc++.h>



#define NN 100011

using namespace std;

typedef long long INT;

	



int main(){

	int n,i,j,u;

	cin>>n;

	int ans=0;

	for(i=0; i<n; i++){

		int tmp=0;

		for(j=0; j<3; j++){

			scanf("%d", &u);

			tmp+=u;

		}

		if(tmp>1) ans++;

	}

	cout<<ans<<endl;

	return 0;

}