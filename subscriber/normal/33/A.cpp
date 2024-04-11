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

int n,m,k,ans=0,x,y,d[10000];

int main(){
	cin >> n >> m >> k;
	for (int i=0;i<m;i++)d[i]=100000000;
	for (int i=0;i<n;i++){
		cin >> x >> y;
		d[x-1]=min(d[x-1],y);
	}
	for (int i=0;i<m;i++)ans+=d[i];
	cout << min(ans,k) << endl;
	return 0;
}