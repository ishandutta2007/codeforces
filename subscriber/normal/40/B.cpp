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

int n,m,x,t;

int main(){
//	freopen("1.in","r",stdin);
//	freopen("1.out","w",stdout);
	cin >> n >> m >> x;
	t=1;
	while (n>0&&m>0){
		if (t==x){
			if (n==1&&m==1)cout << 1 << endl;else
			if (n==1||m==1)cout << max(n+1,m+1)/2 << endl;else
			cout << (n+n+m+m-4)/2 << endl;
			return 0;
		}	
		t++;
		n-=2;
		m-=2;
	}
	cout << 0 << endl;
	return 0;
}