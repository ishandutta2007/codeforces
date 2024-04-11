#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int t,n,c[300030];

inline int check(int n){
	int flag = 2;
	for(int i=1;i < n;i++)
		if(c[i] <= c[i+1]){
			flag--;
			break;
		}
	for(int i=1;i < n;i++)
		if(c[i] >= c[i+1]){
			flag--;
			break;
		}
	return flag;
}

int main()
{
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(int i=1;i <= n;i++)
			scanf("%d",&c[i]);
/*		if(check(n)){
			puts("Yes");
			continue;
		}
*/		int x = 1,y = n;
		while(c[x] >= x-1 && x <= n) x++;
		while(c[y] >= n-y && y >= 1) y--;
		x-1 >= y+1 ? puts("Yes") : puts("No");
/*		if(c[x] == x-2 && x <= n && --c[x] < 0){
			puts("No");
			continue;
		}
		int y = x+1;
		while(c[y] >= c[x]-(y-x) && c[x]-(y-x) >= 0 && y <= n) y++;
		y > n ? puts("Yes") : puts("No");
*/	}
	return 0;
}