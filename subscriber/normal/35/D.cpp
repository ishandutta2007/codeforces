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

int ans,n,s,a[100000],x;

int main(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	cin >> n >> s;
	for (int i=0;i<n;i++){
		cin >> x;
		a[i]=x*(n-i);
	}
	sort(a,a+n);
	for (int i=0;i<n;i++)if (a[i]>s)break;else{
		s-=a[i];
		ans++;
	}
	cout << ans << endl;
	return 0;
}