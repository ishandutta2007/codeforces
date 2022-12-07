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
#include <math.h>
#include <time.h>

using namespace std;

int n,l,ans=0,a[111],s=0;

int main(){
//	freopen("1.in","r",stdin);
//	freopen("1.out","w",stdout);
	cin >> n >> l;
	for (int i=0;i<n;i++)cin >> a[i];
	for (int i=0;i<n;i++)s+=a[i];
	for (int i=1;i<11111;i++)for (int j=l;i*j<=s;j++){
		int t=0;
		for (int k=0;k<n;k++)t+=a[k]/j;
		if (t>=i&&i*j>ans)ans=i*j;
	}
	cout << ans << endl;
	return 0;
}