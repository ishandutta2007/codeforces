#include<bits/stdc++.h>
using namespace std;

char s[200009] = "0";

int main()
{
	int n, t;
	cin >> n >> t;
	scanf("%s", s+1);
	int p = 1;
	while(s[++p] != '.');
	int q = n;
	for(int i = p + 1; i <= n; ++i) if(s[i] >= '5') {
		q = i;
		break;
	}
	for(int i = q + 1; i <= n; ++i) s[i] = 0;
	while(t && q > p && s[q] >= '5') {
		s[q--] = 0;
		++s[q];
		--t;
	}
	if(s[p] > '.') {
		s[p--] = 0;
		++s[p];
	}
	while(s[p] > '9') {
		s[p--] = '0';
		++s[p];
	}
	puts(s[0] > '0' ? s : s+1);
	return 0;
}