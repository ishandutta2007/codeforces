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

int n,l1,l2,ans,a[10000];

int main(){
//	freopen("1.in","r",stdin);
//	freopen("1.out","w",stdout);
	cin >> n;
	for (int i=0;i<n;i++)cin >> a[i];
	ans=abs(a[0]-a[n-1]);
	l1=0;
	l2=n-1;
	for (int i=1;i<n;i++)if (abs(a[i]-a[i-1])<ans){
		ans=abs(a[i]-a[i-1]);
		l1=i;
		l2=i-1;
	}
	cout << (l1+1) << " " << (l2+1) << endl;
	return 0;
}