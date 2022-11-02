#include<bits/stdc++.h>
using namespace std;

#define N 200020
char s[N], t[N];
int cnt;

int main(){
	gets(s);
	int len = strlen(s);
	for(int i = 0; i < len; i ++){
		if(s[i] == t[cnt]){ cnt --; }
		else { t[ ++ cnt] = s[i]; }
	}
	if(cnt == 0) puts("YES");
	else puts("NO");
}