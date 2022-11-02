#include <bits/stdc++.h>
using namespace std;

char s[105];
int a[10], id[10], ans;

bool cmp(int i, int j){
	return a[i] < a[j];
}

int main(){
	int i, b;
	for(i = 0; i < 4; i++){
		scanf("%s", s);
		a[i] = strlen(s) - 2;
		id[i] = i;
	}
	sort(id, id + 4, cmp);
	if(a[id[0]] * 2 <= a[id[1]]) ans++, b = id[0];
	if(a[id[3]] >= 2 * a[id[2]]) ans++, b = id[3];
	if(ans != 1) puts("C");
	else putchar('A' + b);
}