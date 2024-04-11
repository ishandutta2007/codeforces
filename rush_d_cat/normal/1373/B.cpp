#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 10002;
int t;
char s[N];
int main() {
	scanf("%d", &t);
	while (t --) {
		scanf("%s", s+1);
		int a=0,b=0;
		for(int i=1;s[i];i++)
			if(s[i]=='1')a++;else b++;
		printf("%s\n", min(a,b)%2==0?"NET":"DA");
	}
}