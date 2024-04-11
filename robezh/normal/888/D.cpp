#include<iostream>
#include<string>
using namespace std;

long long n, k;

int main(){
	cin >> n >> k;
	long long ans = 0;
	ans += 1;
	if(k >= 2) ans += (n * (n - 1)) / 2;
	if(k >= 3) ans += (n * (n - 1) * (n - 2)) / 6 * 2;
	if(k >= 4) ans += (n * (n - 1) * (n - 2) * (n - 3)) / 24 * 9;
	cout << ans;
}