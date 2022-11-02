#include <bits/stdc++.h>



#define NN 100011

using namespace std;

typedef long long INT;

typedef pair<int, int> pii;



int a[NN];



int main() {



	int n,c,i,j;

	cin>>n>>c;

	for(i=0; i<n; i++) scanf("%d", a+i);

	int mx=-100000;

	for(i=0; i<n-1; i++) mx=max(a[i]-a[i+1], mx);

	mx-=c;

	cout<<max(0, mx)<<endl;





	return 0;

}