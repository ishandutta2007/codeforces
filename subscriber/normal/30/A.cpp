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

int a,b,n;

int main(){
	cin >> a >> b >>n;
	for (int i=-10000;i<=10000;i++){
		long long t=a;
		for (int j=0;j<n;j++){
			if (abs(t)>2000)break;
			t*=i;
		}
		if (t==b){
			cout << i << endl;
			return 0;
		}
	}
	puts("No solution");
	return 0;
}