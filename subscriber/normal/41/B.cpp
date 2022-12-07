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

int n,b,ans=0,a[2222];

int main(){
	cin >> n >> b;
	for (int i=0;i<n;i++)cin >> a[i];
	for (int i=0;i<n;i++)for (int j=i;j<n;j++)ans=max(ans,b/a[i]*a[j]+b%a[i]);
	cout << ans << endl;
	return 0;
}