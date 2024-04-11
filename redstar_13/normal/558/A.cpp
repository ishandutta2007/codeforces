#include <bits/stdc++.h>



#define NN 111

using namespace std;

typedef long long INT;

typedef pair<int, int> pii;



pii x[NN], y[NN];



int main() {

	int n,i,j;

	int  nx=0, ny=0;

	cin>>n;

	for(i=0; i<n; i++){

		int u, v;

		scanf("%d %d", &u, &v);

		if(u<0) x[nx].first=-u, x[nx++].second=v;

		else y[ny].first=u, y[ny++].second=v;

	}

	

	sort(x, x+nx);

	sort(y, y+ny);

	x[nx].second=0, y[ny].second=0;

	

	int ans=0;

	int mn=min(nx, ny);

	for(i=0; i<min(nx, ny); i++) ans+=x[i].second+y[i].second;

	ans+=max(x[mn].second, y[mn].second);

	cout<<ans<<endl;

	





	return 0;

}