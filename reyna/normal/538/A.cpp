//In the name of God
#include <bits/stdc++.h>
using namespace std;
#define For(i,a,b) for(int (i)=(a);(i) < (b); ++(i))
#define Rof(i,a,b) for(int (i)=(a);(i) >= (b); --(i))
#define mkp make_pair
#define XX first
#define YY second
#define pb push_back
const int Maxn = 2e6 + 9;
typedef long long ll;
int main(){
	string S;
	cin >> S;
	for(int i = 0; i < S.size();i++){
		for(int j = i; j < S.size();j++){
			string P = "";
			for(int k = 0; k < S.size();k++){
				if(k < i || k > j) P += S[k];
			}
			if(P == "CODEFORCES"){
				cout << "YES\n";
				return 0;
			}
		}
	}
	cout << "NO\n";
	return 0;
}