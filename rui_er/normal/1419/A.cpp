//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
using namespace std;

int T, n;
string s; 

int main() {
	scanf("%d", &T);
	while(T--) {
		scanf("%d", &n);
		cin>>s;
		s = ' ' + s;
		for(int i=1;i<=n;i++) {
			int digit1 = (s[i] ^ 48);
			s[i] = ((digit1 & 1) ^ 48);
		}
		for(int i=1;i<n;i++) {
			int v = (i&1)?1:2;
			bool _ = true;
			for(int j=v;j<=n;j+=2) {
				if(s[j] == '0' && (i&1) || s[j] == '1' && !(i&1)) {
					s[j] = '@';
					_ = false;
					break;
				}
			}
			if(_) {
				for(int j=v;j<=n;j+=2) {
					if(s[j] != '@') {
						s[j] = '@';
						break;
					}
				}
			}
//			cout<<"TEST: "<<s<<endl;
		}
//		cout<<"TEST: "<<s<<endl;
		for(int i=1;i<=n;i++) {
			if(s[i] != '@') {
				char c = s[i];
				if(c == '0') c = '2';
				putchar(c);
				putchar('\n');
				break;
			}
		}
	}
	return 0;
}