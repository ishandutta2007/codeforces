#include <bits/stdc++.h>
using namespace std;
char s[100100], t[100100];
int main(){
	int n; scanf("%d", &n);
	scanf("%s%s", s + 1, t + 1);
	int c = 0, d = 0;
	for(int i = 1; i <= n; i++){
		if(s[i] == '1' && t[i] == '0')
			c++;
		if(s[i] == '1')
			d++;
	}
	long long ans = 0;
	for(int i = 1; i <= n; i++)
		if(s[i] == '0'){
			if(t[i] == '0') ans += d;
			else ans += c;
		}
	printf("%I64d\n", ans);
	return 0;
}