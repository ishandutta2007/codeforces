//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
using namespace std;

int T;
string s;

int main() {
	scanf("%d", &T);
	while(T--) {
		cin>>s;
		int l = s.length();
		printf("%c", s[0]);
		for(int i=1;i<l-1;i+=2) {
			printf("%c", s[i]);
		}
		printf("%c\n", s[l-1]);
	}
	return 0;
}