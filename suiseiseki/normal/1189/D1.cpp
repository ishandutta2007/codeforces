#include<iostream>
using namespace std;
int a[100006];
int main(void) {
	int n,x,y;
	cin>>n;
	for(int i=1; i<n; i++)cin>>x>>y,a[x]++,a[y]++;
	for(int i=1; i<=n; i++)if(a[i]==2) {
			cout<<"NO";
			return 0;
		}
	cout<<"YES";
}