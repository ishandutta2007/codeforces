#include <bits/stdc++.h>
using namespace std;
map<string, bool> mmap;
char s[1010];
int main(){
	int n; scanf("%d", &n);
	for(int i = 1; i <= n; i++){
		scanf("%s", s);
		if(mmap[s]) printf("YES\n");
		else printf("NO\n"), mmap[s] = true;
	}
	return 0;
}