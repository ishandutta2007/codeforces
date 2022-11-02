#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

const int N = 1e5+10;

int t,c[N],w[N],n,x,y;

int main()
{
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(int i=1;i <= n;i++)
			scanf("%d",&c[i]);
		for(int i=1;i <= n;i++)
			scanf("%d",&w[i]);
		x = y = n+1;
		for(int i=1;i <= n;i++)
			if(c[i] == 1 && x == n+1) x = i;
			else if(c[i] == -1 && y == n+1) y = i;
		int flag = 0;
		for(int i=1;i <= n;i++){
			if(i > x && i > y) break;
			if((c[i] < w[i] && i <= x) || (c[i] > w[i] && i <= y)){
				flag = 1;break;
			}
		}
		flag ? puts("NO") : puts("YES");
 
	}
}