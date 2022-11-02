#include <bits/stdc++.h>



#define NN 100011

using namespace std;

typedef long long INT;

typedef pair<int, int> pii;





int main() {

	int n,i,j,k;

	cin>>n>>k;

	for(i=1; i<=k; i++){

		printf("%d %d ", i*2, i*2-1);

	}

	for(i=k+1; i<=n; i++){

		printf("%d %d ", i*2-1, i*2);

	}





	return 0;

}