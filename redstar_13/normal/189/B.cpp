#include <bits/stdc++.h>
using namespace std;
typedef long long INT;
int main() {
#ifndef ONLINE_JUDGE  
	freopen("b.txt", "r", stdin);
#endif
	int w,h,i,j;
	cin>>w>>h;
	int p=0,k=0;
	for(i=0;i<=w-2;i++)	 p+=(w-i)/2;
	for(j=0;j<=h-2;j++)  k+=(h-j)/2;
	cout<<(INT)p*k<<endl;
}