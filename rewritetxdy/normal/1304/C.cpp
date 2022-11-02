#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;
const int N = 110;

int q,n,m,t[N],l[N],r[N],maxx,minn;

int main()
{
	scanf("%d",&q);
	while(q--){
		scanf("%d%d",&n,&m);
		for(int i=1;i <= n;i++)
			scanf("%d%d%d",&t[i],&l[i],&r[i]);
		maxx = minn = m;
		int flag = 0;
		for(int i=1;i <= n;i++){
			maxx += t[i]-t[i-1];
			minn -= t[i]-t[i-1];
			maxx = min(maxx,r[i]);
			minn = max(minn,l[i]);
			if(minn > maxx){
				puts("NO");
				flag = 1;
				break;
			}
		}
		if(!flag)
			puts("YES");
	}
}