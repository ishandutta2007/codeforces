#include<bits/stdc++.h>
using namespace std;
const int maxn = 10000000;
int s[maxn], t[maxn];
int main(){
	int a, b, c, d; scanf("%d%d%d%d", &a, &b, &c, &d);
	for(int i = b; i < maxn; i += a) s[i] = true;
	for(int i = d; i < maxn; i += c) t[i] = true;
	int ans = -1;
	for(int i = 1; i < maxn; i++)
		if(s[i] && t[i]){
			ans = i;
			break;
		}
	printf("%d\n", ans);
	return 0;
}