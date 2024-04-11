#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;

int n,k;
int num[500050];

int main(){
	long long sum = 0;
	scanf("%d%d", &n, &k);
	for(int i = 0; i < n; i++) scanf("%d", &num[i]), sum += num[i];

	sort(num, num+n);

	long long s = 0, t;
	int i, poor, rich;
	int sum1 = 0;
	for(i = 0; i < n-1; i++){
		t = s + (long long)(i+1) * (num[i+1] - num[i]);
		if(t > k) break;
		s = t;
	}
	poor = num[i] + (k - s) / (i + 1);

	s = 0;
	for(i = n-1; i >= 0; i--){
		t = s + (long long)(num[i] - num[i-1]) * (n - i);
		if(t > k) break;
		s = t;
	}
	rich = num[i] - (k - s) / (n - i);
	int res = max(sum % n == 0 ? 0 : 1, rich - poor);

	cout << res;

}