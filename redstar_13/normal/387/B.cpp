#include <bits/stdc++.h>



#define NN 3333

using namespace std;

typedef long long INT;

typedef pair<int, int> pii;



int a[NN], b[NN];



int main() {



	int n,m,i,j;

	cin>>n>>m;

	

	for(i=0; i<n; i++) scanf("%d", a+i);

	for(i=0; i<m; i++) scanf("%d", b+i);

	

	int pos=m-1;

	int ans=0;

	for(i=n-1; i>=0; i--){

		if(pos<0) break;

		if(b[pos]>=a[i]) pos--;

		else ans++;

	}

	ans+=i+1;

	cout<<ans<<endl;



	return 0;

}