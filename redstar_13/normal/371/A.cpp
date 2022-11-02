#include <bits/stdc++.h>



#define NN 100011

using namespace std;

typedef long long INT;

typedef pair<int, int> pii;



int a[111];



int main() {

	int n,k,i,j;

	cin>>n>>k;

	for(i=1; i<=n; i++){

		scanf("%d", a+i);

	}

	int ans=0, c[3];

	for(i=1; i<=k; i++){

		c[1]=0, c[2]=0;

		for(j=i; j<=n; j+=k){

			c[a[j]]++;

		}

		ans+=min(c[1], c[2]);

	}

	cout<<ans<<endl;





	return 0;

}