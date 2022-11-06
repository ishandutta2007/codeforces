//By: Luogu@rui_er(122461).
#include <bits/stdc++.h>
using namespace std;

int n, m;
map<string, string> mp;

int main() {
	scanf("%d%d", &n, &m);
	while(m--) {
		string a, b;
		cin>>a>>b;
		if(a.length() <= b.length()) mp[a] = mp[b] = a;
		else mp[a] = mp[b] = b;
	}
	while(n--) {
		string s;
		cin>>s;
		cout<<mp[s]<<" ";
	}
	return 0;
}