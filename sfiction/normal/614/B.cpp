#include <cstdio>
#include <cstring>

const int MAXL = 1E5 + 10;

char front[MAXL], s[MAXL];

int main(){
	int n;
	scanf("%d", &n);
	int tail = 0;
	strcpy(front, "1");
	for (int t, i = 0; i < n; ++i){
		scanf("%s", s);
		bool flag = s[0] == '1';
		int j = 1;
		for (; s[j] && (flag &= s[j] == '0'); ++j);
		if (flag)
			tail += j - 1;
		else if (strcmp(front, "0"))
			strcpy(front, s);
	}
	if (strcmp(front, "0") == 0)
		puts("0");
	else{
		printf("%s", front);
		for (int i = 0; i < tail; ++i)
			putchar('0');
		puts("");
	}
	return 0;
}