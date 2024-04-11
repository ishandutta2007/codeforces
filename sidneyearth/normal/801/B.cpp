#include <bits/stdc++.h>
using namespace std;
const int maxn = 210;
char s[maxn], t[maxn];
int main(){
	scanf("%s%s", s, t);
	int n = strlen(s);
	bool flag = true;
	for(int i = 0; i < n; i++)
		if(s[i] < t[i]) flag = false;
	if(flag) printf("%s\n", t);
	else printf("-1\n");
	return 0;
}