//In the name of God
#include <bits/stdc++.h>
using namespace std;
int main(){
	string S;
	cin >> S;
//	if(S.size() < 3){
//		if((S[i] - '0') % 8 == 0) {
//			cout << "YES\n";
//			cout << S[i] << endl;
//			return 0;
//		}
//		if((S[j] - '0') % 8 == 0){
//			cout << "YES\n";
//			cout << S[i] << endl;
//			return 0;
//		}
//		if(((S[i] - '0') * 10 + S[j] - '0') % 8 == 0){
//			cout << "YES\n";
//			cout << S[i] << endl;
//			return 0;
//		}
//		cout << "NO\n";
//		return 0;
//	}
	for(int i = 0; i < S.size();i++){
		for(int j = i + 1; j < S.size();j++){
			for(int k = j + 1; k < S.size();k++){
				if(((S[i] - '0') * 100 + (S[j] - '0') * 10 + S[k] - '0') % 8 == 0){
					cout << "YES\n";
					for(int r = 0; r < i;r++) cout << S[r];
					cout << S[i] << S[j] << S[k];
					return 0;
				}
			}
		}
	}
	for(int i = 0; i < S.size();i++){
		for(int j = i + 1; j < S.size();j++){
			if(S[i] != '0' && ((10 * (S[i] - '0')) + S[j] - '0')% 8 == 0){
				cout << "YES\n";
				cout << S[i] << S[j];
				return 0;
			}
		}
	}
	for(int i = 0; i < S.size();i++){
		if((S[i] - '0') % 8 == 0){
			cout << "YES\n";
			cout << S[i] << endl;
			return 0;
		}
	}
	cout << "NO\n";
}