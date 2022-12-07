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

int n,k,ans=0,a[10000];

int main(){
	cin >> n >> k;
	for (int i=0;i<n;i++)cin >> a[i];
	sort(a,a+n);
	for (int i=0;i<k;i++)if (a[i]<0)ans-=a[i];
	cout << ans << endl;
	return 0;
}