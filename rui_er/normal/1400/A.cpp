//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
using namespace std;

int T, n;

int main() {
	scanf("%d", &T);
	while(T--) {
		scanf("%d", &n);
		string s;
		cin>>s;
		for(int i=0;i<2*n-1;i+=2) printf("%c", s[i]);
		puts("");
	}
	return 0;
}