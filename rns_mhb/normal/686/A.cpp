#include <bits/stdc++.h>
using namespace std;

char s[10];
int d, ans;
long long pack;

int main(){
	int i, j, n, x;
	scanf("%d %d", &n, &x);
	pack = x;
	while(n--){
		scanf("%s %d", s, &d);
		if(s[0] == '+') pack += d;
		else{
			if(pack >= d) pack -= d;
			else ans++;
		}
	}
	printf("%I64d %d", pack, ans);
}