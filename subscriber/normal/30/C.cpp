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

struct T{long long x,y,t; long double p;} q[2000];

bool my(T A,T B){
	return A.t>B.t;
}

int n;
long double f[2000],ans=-1;

int main(){
	cin >>n;
	for (int i=0;i<n;i++)cin >> q[i].x >> q[i].y >> q[i].t >> q[i].p;
	sort(q,q+n,&my);
	for (int i=0;i<n;i++)f[i]=q[i].p;
	for (int i=0;i<n;i++)for (int j=0;j<i;j++)
	if ((q[i].x-q[j].x)*(q[i].x-q[j].x)+(q[i].y-q[j].y)*(q[i].y-q[j].y)<=
	(q[i].t-q[j].t)*(q[i].t-q[j].t))f[i]=max(f[i],f[j]+q[i].p);
	for (int i=0;i<n;i++)ans=max(ans,f[i]);
	cout.precision(9);
	cout << ans << endl;
	return 0;
}