//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
using namespace std;

int n, m;
string s;
char readChar() {
	char c = getchar();
	for(;c<'a'||c>'z';c=getchar());
	return c;
}

int main() {
	scanf("%d%d", &n, &m);
	cin>>s;
	s = ' ' + s;
	while(m--) {
		int l, r;
		char c1, c2;
		scanf("%d%d", &l, &r);
		c1 = readChar();
		c2 = readChar();
		for(int i=l;i<=r;i++) if(s[i] == c1) s[i] = c2;
	}
	cout<<s.substr(1)<<endl;
	return 0;
}