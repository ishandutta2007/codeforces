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

int main(){
//	freopen("1.in","r",stdin);	
//	freopen("1.out","w",stdout);	
	int n,m,h,s=0,a[1111];
	long double ans=1;
	cin >> m >> n >> h;
	h--;
	for (int i=0;i<n;i++)cin >> a[i];
	a[h]--;
	for (int i=0;i<n;i++)s+=a[i];
	if (m>s+1){
		puts("-1");
		return 0;
	}
	for (int i=0;i<m-1;i++)ans*=(s-a[h]-i)/1./(s-i);
	cout.precision(8);
	cout << fixed << (1-ans) << endl;
	return 0;
}