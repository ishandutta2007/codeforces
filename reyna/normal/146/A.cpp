//In the name of God
#include <iostream>
using namespace std;
int main(){
	int n;
	cin >> n;
	string S;
	cin >> S;
	int sum = 0;
	for(int i = 0; i < n;i++){
		if(S[i] != '4' && S[i] != '7'){
			cout << "NO" << endl;
			return 0;
		}
		if(i < n/2)
			sum+=S[i]-'0';
		else
			sum-=S[i]-'0';
	}
	if(sum){
		cout << "NO" << endl;
		return 0;
	}
	cout << "YES" << endl;
	return 0;
}