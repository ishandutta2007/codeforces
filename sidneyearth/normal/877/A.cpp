#include <bits/stdc++.h>
using namespace std;
const int maxn = 1010;
char s[maxn];
char t[5][20] = {"Danil", "Olya", "Slava", "Ann", "Nikita"};
int main(){
	scanf("%s", s);
	int n = strlen(s), ans = 0;
	for(int k = 0; k < 5; k++)
		for(int i = 0; i + strlen(t[k]) <= n; i++){
			bool flag = true;
			for(int j = 0; j < strlen(t[k]); j++)
				if(s[i + j] != t[k][j]) flag = false;
			ans += flag;
		}
	printf("%s\n", ans == 1 ? "YES" : "NO");

	return 0;
}