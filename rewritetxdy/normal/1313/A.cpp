#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;
typedef long long ll;

int t,x,y,z;

int main()
{
	scanf("%d",&t);
	while(t--){
		scanf("%d%d%d",&x,&y,&z);
		if(x <= y) swap(x,y);
		if(x <= z) swap(x,z);
		int ans = 0;
		if(x) x-- , ans++;
		if(y) y-- , ans++;
		if(z) z-- , ans++;
		if(x&&y) x--,y--,ans++;
		if(x&&z) x--,z--,ans++;
		if(y&&z) y--,z--,ans++;
		if(x&&y&&z) ans++;
		printf("%d\n",ans);
	}
}