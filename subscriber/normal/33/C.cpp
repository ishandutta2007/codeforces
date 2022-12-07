#include <iostream>
#include <sstream>
#include <cstring>
#include <stdio.h>
#include <algorithm>
#include <queue>
#include <vector>
#include <set>
#include <map>
#include <memory.h>

using namespace std;

int n,a[111111];
long long f[111111][3];

int main(){
	cin >> n;
	for (int i=0;i<n;i++)scanf("%d",&a[i]);
	for (int i=0;i<=n;i++)for (int j=0;j<3;j++)f[i][j]=-1000001000;
	f[0][0]=0;
	for (int i=0;i<n;i++)for (int j=0;j<3;j++){
		if (j==2)f[i+1][j]=max(f[i+1][j],f[i][j]-a[i]);else
		if (j==1){
			f[i+1][2]=max(f[i+1][2],f[i][j]-a[i]);
			f[i+1][1]=max(f[i+1][1],f[i][j]+a[i]);
		}else{
			f[i+1][1]=max(f[i+1][1],f[i][j]+a[i]);
			f[i+1][0]=max(f[i+1][0],f[i][j]-a[i]);
		}
	}
	cout << max(f[n][0],max(f[n][1],f[n][2])) << endl;
	return 0;
}