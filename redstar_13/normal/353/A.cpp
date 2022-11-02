#include <bits/stdc++.h>



#define NN 100011

using namespace std;

typedef long long INT;

typedef pair<int, int> pii;





int main() {

	int n,i,j;

	cin>>n;

	int s=0, t=0;

	int t1=-1, t2=-1;

	for(i=0; i<n; i++) {

		int u,v;

		scanf("%d %d", &u, &v);

		s+=u, t+=v;

		if(u&1 && v%2==0) t1=u, t2=v;

		if(u%2==0 && v&1) t1=u, t2=v;

	}

	if(s%2==0 && t%2==0) cout<<0<<endl;

	else if(s&1 && t&1 && t1!=-1) cout<<1<<endl;

	else puts("-1");





	return 0;

}