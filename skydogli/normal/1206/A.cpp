#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],b[105],vis[405];
int main(){
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>a[i];
		vis[a[i]]++;
	}
	cin>>m;
	for(int j=1;j<=m;++j)	{
		cin>>b[j];
		vis[b[j]]++;
	}
	for(int i=1;i<=n;++i)
	for(int j=1;j<=m;++j){
		if(!vis[a[i]+b[j]]){
			cout<<a[i]<<" "<<b[j]<<endl;
			return 0;
		}
	}
	return 0;
}