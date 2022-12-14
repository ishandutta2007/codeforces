//In the name of God
#include <iostream>
using namespace std;
int ans[2];
int main(){
	int n;
	cin >> n;
	string S;
	cin >> S;
	for(int i = 0; i < n;i++){
		ans[(S[i]-'0' + i % 2)%2]++;
	}
	cout << min(n-ans[0],n-ans[1]) << endl;
	return 0;
}