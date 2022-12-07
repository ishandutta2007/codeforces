#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<string>
#include<map>

using namespace std;

int n,m,x,y,f[1111];

int main(void){
//	freopen("1.in","r",stdin);
//	freopen("1.out","w",stdout);
	cin >> n >> m;
	for (int i=0;i<m;i++){
		cin >> x >> y;
		for (int j=x;j<=y;j++)f[j]++;
	}			
	for (int i=1;i<=n;i++)if (f[i]!=1){
		cout << i << " " << f[i] << endl;
		return 0;
	}
	puts("OK");
	return 0;
}