#include <bits/stdc++.h>
using namespace std;
int n,m,a[105],b[105],mx1,mx2;
int main(){
	cin>>n;for(int i=1;i<=n;i++)	cin>>a[i];
	cin>>m;for(int i=1;i<=m;i++)	cin>>b[i];
	cout<<*max_element(a+1,a+1+n)<<" "<<*max_element(b+1,b+1+m)<<endl;
}////////