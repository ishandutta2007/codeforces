//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+5;

int T, x;
string s;
int col[N];

int main() {
	scanf("%d", &T);
	while(T--) {
		cin>>s;
		scanf("%d", &x);
		int l = s.length();
		for(int i=0;i<l;i++) col[i] = 2;
		for(int i=0;i<l;i++) {
			char c = s[i];
			if(c == '0') {
				if(i - x >= 0) col[i-x] = 0;
				if(i + x < l) col[i+x] = 0;
			}
		}
		bool __ = true;
		for(int i=0;i<l;i++) {
			char c = s[i];
			if(c == '1') {
				bool _ = false;
				if(i - x >= 0) if(col[i-x] == 2) _ = true;
				if(i + x < l) if(col[i+x] == 2) _ = true;
				if(!_) {
					puts("-1");
					__ = false;
					break;
				}
			}
		}
		if(__) {
			for(int i=0;i<l;i++) {
				if(!col[i]) printf("0");
				else printf("1");
			}
			puts("");
		}
	}
	return 0;
}