//In the name of God
#include <iostream>
using namespace std;
int f[26];
int main(){
	string S,P,T;
	cin >> S >> P >> T;
	for(int i = 0; i < S.size();i++)
		f[S[i]-'A']++;
	for(int i = 0; i < P.size();i++)
		f[P[i]-'A']++;
	for(int i = 0; i < T.size();i++)
		f[T[i]-'A']--;
	for(int i = 0 ;i < 26;i++){
		if(f[i]){
			cout << "NO" << endl;
			return 0;
		}
	}
	cout << "YES" << endl;
	return 0;
}