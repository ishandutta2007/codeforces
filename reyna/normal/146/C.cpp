//In the name of God
#include <iostream>
using namespace std;
int main(){
	string S,P;
	cin >> S >> P;
	int one=0,two=0;
	int n = S.size();
	for(int i = 0; i < n;i++){
		if(S[i] == '7' && P[i] == '4')
			one++;
		if(S[i] == '4' && P[i] == '7')
			two++;
	}
	cout << max(one,two) << endl;
	return 0;
}