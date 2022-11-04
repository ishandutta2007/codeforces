#include <bits/stdc++.h>
using namespace std;

#define MX 300005 
char s[MX];

int main() {
//	freopen("in.txt", "r", stdin);
	
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	int Tc; cin >> Tc;
	while(Tc --) {
		int N; cin >> N >> s;
		bool C = true, NC = true;
		for(int i = 0; i < N; i ++) {
			if(s[i] == '<') C = false;
			else if(s[i] == '>') NC = false;			
		}
		int ans = 0;
		for(int i = 0; i < N; i ++) {
			if(s[i] == '-') ans ++;
			else if(s[(i + N - 1) % N] == '-') ans ++;
			else if(s[i] == '<' && NC) ans ++;
			else if(s[(i + N - 1) % N] == '>' && C) ans ++;
		}
		cout << ans << endl;
	} 
	
	return 0;
}