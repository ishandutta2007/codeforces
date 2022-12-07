#include <stdio.h>
#include <algorithm>
#include <math.h>
#include <memory.h>
#include <map>
#include <set>
#include <queue>
#include <vector>
#include <string>
#include <iostream>

using namespace std;

int n,m,vv1=0,vv2=0,v1[11111],v2[11111],a[111][111];

int main(){
//	freopen("1.in","r",stdin);
//	freopen("1.out","w",stdout);
	cin >> n >> m;
	for (int i=1;i<=n*m;i++)if (i&1)v1[vv1++]=i;else v2[vv2++]=i;
	for (int i=0;i<n;i++)for (int j=0;j<m;j++){
		if (vv1){
			a[i][j]=v1[--vv1];
		}else{
			int x=-9,y=-9;
			if (i)x=a[i-1][j];
			if (j)y=a[i][j-1];
			for (int k=0;k<vv2;k++)if (abs(v2[k]-x)>1&&abs(v2[k]-y)>1){
				a[i][j]=v2[k];
				v2[k]=v2[--vv2];
				break;
			}
		}
		if (!a[i][j]){
			puts("-1");
			return 0;
		}
	}
	for (int i=0;i<n;i++){
		for (int j=0;j<m-1;j++)cout << a[i][j] << " ";
		cout << a[i][m-1] << endl;
	}
	return 0;
}