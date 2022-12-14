//In the name of God
#include <iostream>
using namespace std;
int main(){
	string S;
	cin >> S;
	int cnt = 1;
	int ans = 0;
	int n = S.size();
	for(int i = 1; i < n;i++){
		if(S[i] != S[i-1]){
			ans += cnt / 5;
			if(cnt % 5)
				ans++;
			cnt = 1;
			continue;
		}
		cnt++;
	}
	ans += cnt / 5;
	if(cnt % 5)
		ans++;
	cout << ans << endl;
	return 0;
}