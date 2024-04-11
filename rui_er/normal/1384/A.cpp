//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
using namespace std;

int T, n, a[105]; 
string s[105];

int main() {
	scanf("%d", &T);
	while(T--) {
		scanf("%d", &n);
		s[0] = "";
		for(int i=0;i<50;i++) {
			s[0] += "a";
		}
		for(int i=1;i<=n;i++) {
			scanf("%d", &a[i]);
			s[i] = s[i-1].substr(0, a[i]);
			for(int j=s[i].length();j<50;j++) {
				if(s[i-1][j] == 'a') {
					s[i] += 'b';
				}
				else {
					s[i] += 'a';
				}
			} 
		}
		for(int i=0;i<=n;i++) {
			cout<<s[i]<<endl;
		}
	}
	return 0;
}