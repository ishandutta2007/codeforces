#include<stdio.h>
#include<iostream>
#include<vector>
#include<math.h>
#include<algorithm>
#include<memory.h>
#include<map>
#include<queue>
#include<list>

using namespace std;

int n,nn,an,k[55555],a[41000][202],e[41000][202],q[222],f[222];
vector<int>aa[222];

int main(){
//	freopen("1.in","r",stdin);	
//	freopen("1.out","w",stdout);	
	cin >> n;
	int nn=n*(n-1)/2;
	for (int i=0;i<nn;i++){
		cin >> k[i];
		for (int j=0;j<k[i];j++)cin >> a[i][j];
		for (int j=0;j<k[i];j++)e[i][a[i][j]]=1;
	}
	if (n==2){
		cout << "1 " << a[0][0] << endl;
		cout << k[0]-1;
		for (int i=1;i<k[0];i++)cout << " " << a[0][i];
		puts("");
		return 0;
		
	}
	for (int i=0;i<202;i++)if (!f[i]){
		memset(q,0,sizeof(q));
		int d=0;
		for (int j=0;j<nn;j++)if (e[j][i]){
			d++;
			for (int l=0;l<k[j];l++)q[a[j][l]]++;
		}
		if (!d)continue;
		for (int j=0;j<202;j++)if (q[j]==d){
			f[j]=1;
			aa[an].push_back(j);
		}
		an++;
	}
	for (int i=0;i<n;i++){
		cout << aa[i].size() << " ";
		for (int j=0;j<aa[i].size()-1;j++)cout << aa[i][j] << " ";
		if (aa[i].size())cout << aa[i][aa[i].size()-1] << endl;
	}
	return 0;
}