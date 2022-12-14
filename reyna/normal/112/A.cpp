//In the name of God
#include <iostream>
using namespace std;
int main(){
	string S,P;
	cin >> S >> P;
	for(int i = 0; i < S.size();i++){
		if(S[i] < 'a')
			S[i] += 'a' - 'A';
		if(P[i] < 'a')
			P[i] += 'a' - 'A'; 
	}
	if(S == P){
		cout << 0 << endl;
		return 0;
	}
	if(S > P){
		cout << 1 << endl;
		return 0;
	}
	cout << -1 << endl;
	return 0;
}