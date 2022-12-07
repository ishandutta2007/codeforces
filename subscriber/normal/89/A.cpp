#include<stdio.h>
#include<iostream>
#include<vector>
#include<math.h>
#include<algorithm>
#include<memory.h>
#include<map>
#include<queue>

using namespace std;

int main(){
//	freopen("1.in","r",stdin);	
//	freopen("1.out","w",stdout);	
	long long n,k,m,a,o=1000000;
	cin >> n >> m >> k;
	if (n%2==0){
		puts("0");
		return 0;
	}
	for (int i=0;i<n;i++){
		cin >> a;
		if (i%2==0)o=min(o,a);
	}
	cout << min(m/((n+1)/2)*k,o) << endl;
	return 0;
}