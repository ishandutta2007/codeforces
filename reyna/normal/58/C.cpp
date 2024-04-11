//In the name of God
#include <iostream>
using namespace std;
const int Maxn = 1e5 + 1e3;
int ans[Maxn];
int main(){
	int n;
	cin >> n;
	for(int i = 0; i < n;i++){
		int now;
		cin >> now;
		if(now >= min(n-i-1,i))
			ans[now-min(n-i-1,i)]++;
	}
	int Ans = 0;
	for(int i = 1;i < Maxn;i++){
		Ans = max(Ans,ans[i]);
	}
	cout << n-Ans << endl;
	return 0;
}