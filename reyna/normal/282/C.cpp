//In the name of God
#include <iostream>
#include <cstdio>
using namespace std;
int main(){
	string S,P;
	cin >> S >> P;
	if(S == P){
		cout << "YES" << endl;
		return 0;
	}
	if(S.length() != P.length()){
		cout << "NO" << endl;
		return 0;
	}
	int flag1 = 0;
	for(int i = 0;i < S.size();i++)
		if(S[i] == '1')
			flag1 = 1;
	int flag2 = 0;
	for(int i = 0; i < P.size();i++)
		if(P[i] == '1')
			flag2 = 1;
	if(flag2 && !flag1){
		cout << "NO" << endl;
		return 0;
	}
	if(flag1 && !flag2){
		cout << "NO" << endl;
		return 0;
	}
	cout << "YES" << endl;
	return 0;
}