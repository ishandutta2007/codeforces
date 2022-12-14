//In the name of God
#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;
const int Maxn = 1e5+1e3;
vector<int> ans;
int arr[Maxn];
int rev[Maxn];
int sum[Maxn];
int n;
int rec(int in){
	cerr << in << endl;
	if(in == n)
		return 0;
	int next = rec(in + 1);
//	cerr << next << " :) " << endl;
	if(next < arr[in]){
		rev[in+1] = 1;
		ans.push_back(1);
		return arr[in] - next;
	}
	ans.push_back(0);
	return next - arr[in];
}
int main(){
	scanf("%d",&n);
	for(int i = 0;i < n;i++)
		scanf("%d",&arr[i]);
	rec(0);
	sum[0] = 0;
	for(int i = 1; i < n;i++)
		sum[i] = sum[i-1] + rev[n-i];
	long long S = 0;
	for(int i = n-1; i >= 0;i--){
		if((ans[i] + sum[i])%2)
			S -= arr[n-i-1];
		else
			S += arr[n-i-1];
	}
	if(S < 0){
		for(int i = n-1; i >= 0;i--){
			if((ans[i] + sum[i])%2)
				cout << '+';
			else
				cout << '-';
		}
	}else{
		for(int i = n-1; i >= 0;i--){
			if((ans[i] + sum[i])%2)
				cout << '-';
			else
				cout << '+';
		}
	}
	cout << endl;
	return 0;
}