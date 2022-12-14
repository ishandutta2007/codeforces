//In the name of God
#include <bits/stdc++.h>
using namespace std;
int main(){
	string S,P;
	cin >> S >> P;
	int n = S.size();
	int dis = 0;
	for(int i = 0; i < n;i++) if(S[i] != P[i]) dis++;
	if(dis % 2){
		cout << "impossible\n";
		return 0;
	}
	int c = 0;
	string ans = "";
	for(int i = 0; i < n;i++){
		if(S[i] == P[i]){
			ans += S[i];
			continue;
		}
		if(c % 2) ans += S[i];
		else ans += P[i];
		c++;
	}
	cout << ans << endl;
	return 0;
	
}