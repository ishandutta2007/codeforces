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

int x,y,n,f[11111111],w[11111],q[11111],ms[11111][111],o=0,t[11111];

int sv(int x){
	if (t[x])return 0;
	t[x]=1;
	for (int i=0;i<n;i++)if (ms[x][i]&&q[i]==0){
		q[i]=x+1;
		return 1;
	}
	for (int i=0;i<n;i++)if (ms[x][i]&&sv(q[i]-1)){
		q[i]=x+1;
		return 1;
	}
	return 0;
}

int main(){
//	freopen("1.in","r",stdin);
//	freopen("1.out","w",stdout);
	cin >> n;
	for (int i=0;i<n;i++){
		cin >> x >> y;
		for (int j=x;j<=min(x+n+3,y);j++)if (f[j]){
			ms[f[j]-1][i]=1;
		}else{
			w[o++]=j;
			f[j]=o;
			ms[o-1][i]=1;
		}
	}
	for (int i=0;i<o;i++){
		memset(t,0,sizeof(t));
		sv(i);
	}
	for (int i=0;i<n-1;i++)cout << w[q[i]-1] << " ";
	cout << w[q[n-1]-1] << endl;
	return 0;
}