#include <bits/stdc++.h>



#define NN 100011

using namespace std;



int main() {

	int n,m,i,j,a,b;

	cin>>n>>m>>i>>j>>a>>b;

	

	int ans=1000000000;

	

	int dx[5]={i-1, i-1, n-i, n-i};

	int dy[5]={j-1, m-j, j-1, m-j};

	

	for(i=0; i<4; i++){

		for(j=0; j<4; j++){

			int u=dx[i], v=dy[j];

			if(u%a || v%b) continue;

			int s=u/a, t=v/b;

			if((s+t)%2) continue;

			if(s && t==0 && dy[i]<b) continue;

			if(t && s==0 && dx[j]<a) continue;

			ans=min(ans, max(s, t));

		}

	}

	if(ans==1000000000) puts("Poor Inna and pony!");

	else cout<<ans<<endl;



	return 0;

}