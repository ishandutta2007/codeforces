//2016-06-12 22:16:51.901000
#include <bits/stdc++.h>

using namespace std;

#define NN 1000010
#define rep(i, a, b) for (int i = (a); i < (b); i ++)
 
char str[NN], s[NN];

int main() {
	
	int t, tt, len2, len1;
	scanf("%s", str);
	scanf("%s", s);
	t = tt = -1;
	len1 = strlen(str);
	len2 = strlen(s);
	rep(i, 0, len1) 
		if (str[i] != '0') {
			t = i;
			break ;
		}
	
	rep(i, 0, len2) 
		if (s[i] != '0') {
			tt = i;
			break ;
		}
	if (t == -1 && tt == -1) puts("=");
	else if (t == -1) puts("<");
	else if (tt == -1) puts(">");
	else {
		if (len1 - t > len2 - tt) puts(">");
		else if (len1 - t < len2 - tt) puts("<");
		else {
			int hop = 0;
			rep(i, 0, len1 - t + 1) 
				if (str[i + t] < s[i + tt]) {
					hop = 1;
					break ;
				} else if (str[i + t] > s[i + tt]) {
					hop = 2;
					break ;
				}
			if (hop == 1) puts("<");
			else if (hop == 2) puts(">");
			else puts("=");
		}
	}
	
	return 0;
}