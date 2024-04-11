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

int n,a[222],b[222],c[222],d[333],k=0;
pair<int,int>q[222];

int main(){
//	freopen("1.in","r",stdin);	
//	freopen("1.out","w",stdout);	
	cin >> n;
	for (int i=0;i<n;i++)cin >> a[i] >> b[i] >> c[i] >> d[i];
	for (int i=0;i<n;i++){
		int t=0;
		for (int j=0;j<n;j++)if (a[j]>a[i]&&b[j]>b[i]&&c[j]>c[i])t=1;
		if (!t)q[k++]=make_pair(d[i],i);
	}
	sort(q,q+k);
	cout << q[0].second+1 << endl;
	return 0;
}