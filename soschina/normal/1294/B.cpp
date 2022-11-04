#include <cstdio>
#include <iostream>
#include <algorithm> 
#define x first
#define y second
using namespace std;
const int N = 1001;
typedef pair<int, int> duo;

int t, n, len;
duo a[N];
char s[2001];

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		for(int i = 1; i <= n; i++)
			scanf("%d%d", &a[i].x, &a[i].y);
		sort(a + 1, a + 1 + n);
		bool flag = true;
		for(int i = 1; i <= n && flag; i++)
			flag = a[i - 1].y <= a[i].y;
		if(flag){
			len = 0;
			printf("YES\n");
			for(int i = 1; i <= n; i++){
				int tmp = a[i].x - a[i - 1].x;
				while(tmp--) putchar('R');
				tmp = a[i].y - a[i - 1].y;
				while(tmp--) putchar('U');
			}
			putchar('\n');
		}else printf("NO\n");
	}
	return 0;
}