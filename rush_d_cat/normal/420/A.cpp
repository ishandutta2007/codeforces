#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=100000+10;
bool chk(char c) {
	//ABCDEFGHIJKLMOPQRSTUVWXYZ
	if(c=='A'||c=='H'||c=='I'||c=='M'||c=='O'||c=='T'||c=='U'||c=='V'||c=='W'||c=='X'||c=='Y') return 1;
	return 0;
}
char s[N];
int main() {
	scanf("%s",s+1);
	for(int i=1;s[i];i++)if(!chk(s[i]))return !printf("NO\n");
	int n=strlen(s+1);
	for(int i=1;i<=n;i++)if(s[i]!=s[n+1-i])return !printf("NO\n");
	return !printf("YES\n");
}