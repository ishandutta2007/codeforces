#include <bits/stdc++.h>
using namespace std;

#define TOP_N 105

int n, a[TOP_N], b[TOP_N];

void func(int k){
	if(k == n + 1)	return;
	else{//cout<<"k"<<k<<",";
		//for(int i = 1; i <= n - (k - 1); i ++)	cout<<a[i];
		//cout<<endl;
		int x = 2000000000, y;
		for(int i = 1; i <= n - (k - 1); i ++){
			if(x > a[i]){
				x = a[i], y = i;
			}
		}
		for(int i = k - 1 + y; i >= k + 1; i --)	printf("%d %d\n", i - 1, i);
		for(int i = 1; i < y; i ++)	b[i] = a[i];
		for(int i = y; i <= n - k; i ++)	b[i] = a[i + 1];
		for(int i = 1; i <= n - k; i ++)	a[i] = b[i];
		func(k + 1);
	}
}

int main(){
	//freopen("sample.in", "r", stdin);
	scanf("%d", &n);
	for(int i = 1; i <= n; i ++)	scanf("%d", &a[i]);
	func(1);
}