//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
using namespace std;
const int N = 1005, inf = 0x3f3f3f3f;

int n, a[N] = {1};
string s;

int main() {
	scanf("%d", &n); cin>>s;
	for(int i=0;i<n-1;i++) {
		if(s[i] == '=') a[i+1] = a[i];
		else if(s[i] == 'R') a[i+1] = a[i] + 1;
		else {
			a[i+1] = 1;
			if(a[i] == 1) {
				for(int j=i;j>=0;j--) {
					if(s[j] == '=') a[j] = a[j+1];
					else if(s[j] == 'L' && a[j] == a[j+1]) ++a[j];
					else break;
				}
			}
		}
	}
	for(int i=0;i<n;i++) printf("%d ", a[i]);
	return 0;
}