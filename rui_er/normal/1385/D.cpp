//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
using namespace std;

int T, n;
string s;

int f(string a, char c) {
	a = ' ' + a;
	int l = a.length() - 1;
	if(l == 1) {
		return (a[1]==c)?0:1;
	}
	string a1 = a.substr(1, l/2);
	string a2 = a.substr(l/2+1);
	int b1 = 0, b2 = 0;
	for(int i=0;i<a1.length();i++) {
		if(a1[i] != c) {
			++b1;
		}
	}
	for(int i=0;i<a2.length();i++) {
		if(a2[i] != c) {
			++b2;
		}
	}
	return min(b1+f(a2, c+1), b2+f(a1, c+1));
} 

int main() {
	scanf("%d", &T);
	while(T--) {
		scanf("%d", &n);
		cin>>s;
		printf("%d\n", f(s, 'a'));
	}
	return 0;
}