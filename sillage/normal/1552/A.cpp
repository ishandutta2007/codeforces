#include<bits/stdc++.h>
using namespace std;
char s[100], t[110];
void solve(){
	int n;
	cin >> n;
	scanf("%s", s);
	for(int i = 0; i < n; i++) t[i] = s[i];
	sort(s, s + n);
	int cnt = 0;
	for (int i= 0; i < n; i++) if (s[i] != t[i]) cnt++;
	cout << cnt << endl;
}
int main(){
	int T;
	cin >> T;
	while(T--) solve();
}