#include <cstdio>

int p[200];
char s[200];

int main(){
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		scanf("%d", &p[i]);
	getchar();
	bool flag = true;
	for (int i = 0; i < n; ++i){
		gets(s);
		int cnt = 0;
		for (int j = 0; s[j]; ++j)
			cnt += s[j] == 'a' || s[j] == 'e' || s[j] == 'i' || s[j] == 'o' || s[j] == 'u' || s[j] == 'y';
		flag &= p[i] == cnt;
	}
	puts(flag ? "YES" : "NO");
	return 0;
}