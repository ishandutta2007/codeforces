#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

void getStr(char a[]){
	scanf("%s", a);
	scanf("%s", a + 2);
	swap(a[2], a[3]);
	for (int i = 0; i < 3; ++i)
		if (a[i] == 'X'){
			for (int j = i; j < 3; ++j)
				a[j] = a[j + 1];
			return;
		}
	return;
}

char a[10], b[10];

void shift(char a[]){
	char t = a[0];
	a[0] = a[1];
	a[1] = a[2];
	a[2] = t;
}

int main(){
	getStr(a);
	getStr(b);
	a[3] = b[3] = '\0';
	if (strcmp(a, b) == 0)
		puts("YES");
	else if (shift(b), strcmp(a, b) == 0)
			puts("YES");
	else if (shift(b), strcmp(a, b) == 0)
			puts("YES");
	else
		puts("NO");
	return 0;
}