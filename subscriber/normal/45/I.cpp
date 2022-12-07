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

int i,t,n,a[111];

int main(){
//	freopen("1.in","r",stdin);
//	freopen("1.out","w",stdout);
	cin >> n;
	for (int i=0;i<n;i++)cin >> a[i];
	sort(a,a+n);
	i=0;
	t=0;
	while (i<n){
		if (a[i]>0){
			if (t)cout << " ";
			t=1;
			cout << a[i];
			i++;
		}else if (i<n-1&&a[i]<0&&a[i+1]<0){
			if (t)cout << " ";
			t=1;
			cout << a[i] << " " << a[i+1];
			i+=2;
		}else i++;
	}
	if (!t){
		cout << a[n-1] << endl;
	}else
	cout << endl;
	return 0;
}