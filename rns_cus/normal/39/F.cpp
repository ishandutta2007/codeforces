#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n,m, k, d[110], pos[110], cnt[110] = {0}, mn, cn = 0;
	scanf("%d%d%d", &n, &m, &k);
	for( int i = 1; i <= m; i ++ ) scanf("%d", &d[i]);
	for( int i = 1; i <= k; i ++ ) scanf("%d", &pos[i]);
	for( int i = 1; i <= m; i ++ ) for( int j = 1; j <= k; j ++ )
		if(pos[j] % d[i] == 0) cnt[i] ++;
	mn = cnt[1];
	for( int i = 1; i <= m; i ++) if(mn > cnt[i]) mn = cnt[i];
	for( int i = 1; i <= m; i ++) if(mn == cnt[i]) cn ++;
	printf("%d\n",cn);
	for( int i = 1; i <= m; i ++)
		if(mn == cnt[i])
		printf("%d ",i);
	printf("\n");
	return 0;
}