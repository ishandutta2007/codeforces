#include<bits/stdc++.h>



#define NN 55

using namespace std;

typedef long long INT;



int a[NN], b[NN];

int main(){

	int n,i,j,m;

	cin>>n;

	for(i=0; i<n; i++){

		scanf("%d", a+i);

	}

	cin>>m;

	int mx=0;

	for(i=0; i<m; i++){

		scanf("%d", b+i);

		for(j=0; j<n; j++){

			if(b[i]%a[j]==0){

				if(b[i]/a[j]>mx) mx=b[i]/a[j];

			}

		}

	}

	

	int ans=0;

	for(i=0; i<m; i++){

		for(j=0; j<n; j++){

			if(b[i]%a[j]==0 && b[i]/a[j]==mx) ans++;

		}

	}

	

	cout<<ans<<endl;

	

	return 0;

}