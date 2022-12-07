#include<stdio.h>
#include<iostream>
#include<vector>
#include<math.h>
#include<algorithm>
#include<memory.h>
#include<map>
#include<queue>

using namespace std;

int n,m,a[333333],x,y;
long long ans[333333],f[333333];
vector<pair<int,int> >v[633];

int main(){
//	freopen("1.in","r",stdin);	
//	freopen("1.out","w",stdout);	
	cin >> n;
	for (int i=0;i<n;i++)scanf("%d",&a[i]);
	cin >> m;
	for (int i=0;i<m;i++){
		scanf("%d%d",&x,&y);
		if (y<600){
			v[y].push_back(make_pair(i,x));
			continue;
		}
		x--;
		ans[i]=0;
		while (x<n){
			ans[i]+=a[x];
			x+=y;
		}
	}
	for (int i=1;i<600;i++)if (v[i].size()){
		for (int j=n-1;j>=0;j--)if (j+i>=n)f[j]=a[j];else f[j]=a[j]+f[j+i];
		for (int j=0;j<v[i].size();j++)ans[v[i][j].first]=f[v[i][j].second-1];
	}
	for (int i=0;i<m;i++)printf("%I64d\n",ans[i]);
	return 0;
}