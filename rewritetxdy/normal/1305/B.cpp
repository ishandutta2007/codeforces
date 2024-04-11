#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;
typedef long long ll;
const int N = 1010;

int x,y,n,ans[N],cnt;
char c[N];

int main()
{
	scanf("%s",c+1);
	n = strlen(c+1);
	x = 1,y = n;
	while(x < y){
		while(c[x] != '(' && x < y) x++;
		while(c[y] != ')' && x < y) y--;
		if(x < y){
			ans[++cnt] = x , ans[++cnt] = y;
			x++ , y--;
		}
	}
	sort(ans+1,ans+1+cnt);
	if(!cnt){
		puts("0");
		return 0;
	}
	puts("1");
	printf("%d\n",cnt);
	for(int i=1;i <= cnt;i++)
		printf("%d ",ans[i]);
	puts("");
}