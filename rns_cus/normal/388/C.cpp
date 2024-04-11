#include<bits/stdc++.h>
using namespace std;

#define N 100010

typedef long long LL;

int arr[N], cnt;

int n, k, x;

LL sum1, sum2;

int main(){
///	freopen("in.txt", "r", stdin);
	scanf("%d", &n);
	for(int i = 1; i <= n; i ++){
		scanf("%d", &k);
		for(int i = 1; i <= k; i ++){
			scanf("%d", &x);
			if(i <= k / 2) sum1 += x;
			else if(i * 2 == k + 1){
				arr[cnt ++] = x;
			}
			else sum2 += x;
		}
	}

	sort(arr, arr + cnt, greater<int>());
	for(int i = 0; i < cnt; i ++){
		if(i & 1) sum2 += arr[i];
		else sum1 += arr[i];
	}
	cout << sum1 << " " << sum2 << endl;
}