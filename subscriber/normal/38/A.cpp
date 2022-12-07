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

int n,x,y,a[1111],ans=0;

int main(){
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);
	cin >> n;
	for (int i=1;i<n;i++)cin >> a[i];
	a[0]=0;
	cin >> x >> y;
	x--;
	y--;
	for (int i=x+1;i<=y;i++)ans+=a[i];
	cout << ans << endl;
	return 0;
}