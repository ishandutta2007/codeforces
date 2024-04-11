#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

int n,q;
ll c[30][30],ansx[30],ansy[30],z[60];


int main()
{
	z[0] = 1;
	for(int i=1;i <= 60;i++) z[i] = z[i-1] << 1;
	for(int i=2;i <= 24;i += 2){
		c[i][1] = i == 2 ? 1 : (c[i-2][1]<<2);
		for(int j=2;j <= 25;j++) c[i][j] = c[i][j-1]<<1;
	}
	scanf("%d",&n);
	for(int i=1;i <= n;i++){
		for(int j=1;j <= n;j++) cout<<c[i][j]<<' ';
		cout<<endl;
	}
	int q;
	ll w;
	cin>>q;
	while(q--){
		cin>>w;
		int x=1,y=1;
		cout<<x<<' '<<y<<endl;
		for(int i=2;i <= 2*n-1;i++){
			if(x < n && !((w^c[x+1][y])&z[i-2])) x++;
			else y++;
			cout<<x<<' '<<y<<endl; 
		}
	}
}