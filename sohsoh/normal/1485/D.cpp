#include <bits/stdc++.h>
using namespace std;
int main() {int c=720720,n,m,t,x;cin>>n>>m;for(int i=1;i<=n;i++){for (int j=1;j<=m;j++){t=c;cin>>x;if((i+j)&1)t+=x*x*x*x;cout<<t<<' ';}cout<<'\n';}
	return 0;
}