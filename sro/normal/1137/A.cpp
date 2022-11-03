#include <bits/stdc++.h>
using namespace std;

int n,m;
int a[1005][1005];
vector<int> b[1005],c[1005];

int main(){
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			scanf("%d",a[i]+j);
			b[i].push_back(a[i][j]);
			c[j].push_back(a[i][j]);
		}
		sort(b[i].begin(),b[i].end());
		b[i].resize(unique(b[i].begin(),b[i].end())-b[i].begin());
	}
	for(int i=0;i<m;i++){
		sort(c[i].begin(),c[i].end());
		c[i].resize(unique(c[i].begin(),c[i].end())-c[i].begin());
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			int numof=lower_bound(b[i].begin(),b[i].end(),a[i][j])-b[i].begin(),numof2=lower_bound(c[j].begin(),c[j].end(),a[i][j])-c[j].begin();
			printf("%d%c",max(numof,numof2)+max(b[i].size()-numof,c[j].size()-numof2),j==m-1?'\n':' ');
		}
	}
	return 0;
}