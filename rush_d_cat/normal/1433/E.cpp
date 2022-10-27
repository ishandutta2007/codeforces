#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long LL;
const int N = 200000 + 10;
int n;
LL c[23][23],f[22];
int main() {
	f[0]=1;
	for(int i=1;i<=20;i++)f[i]=f[i-1]*i;
	for(int i=0;i<=20;i++)c[i][0]=1;
	for(int i=1;i<=20;i++){
		for(int j=1;j<=i;j++){
			c[i][j]=c[i-1][j-1]+c[i-1][j];
		}
	}
	cin>>n;
	cout<<c[n][n/2]*f[n/2-1]*f[n/2-1]/2<<endl;
}