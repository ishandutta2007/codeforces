#include <bits/stdc++.h>



#define NN 100011

using namespace std;

typedef long long INT;

typedef pair<int, int> pii;





int main() {

	int n,m,i,j;

	cin>>n>>m;

	int mn=1111, mx=0, a;

	for(i=0; i<n; i++) scanf("%d", &a), mn=min(a, mn), mx=max(a, mx);

	mx=max(mx, mn*2);

	

	mn=1111;

	int b;

	for(i=0; i<m; i++) scanf("%d", &b), mn=min(mn, b);

	if(mn>mx) cout<<mx<<endl;

	else puts("-1");





	return 0;

}