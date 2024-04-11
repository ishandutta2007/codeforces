#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;
const int N = 2e5+10;

char c[N];
int n,q,l,r,sum[N][30];

int main()
{
	scanf("%s",c+1);
	n = strlen(c+1);
	for(int i=1;i <= n;i++)
		for(int j=0;j <= 25;j++)
			sum[i][j] = sum[i-1][j] + (c[i] == ('a'+j));
	scanf("%d",&q); 
	while(q--){
		scanf("%d%d",&l,&r);
		if(l == r || c[l] != c[r])
			puts("Yes");
		else{
			int cnt = 0;
			for(int i=0;i <= 25;i++)
				if(sum[r][i] != sum[l-1][i])
					cnt++;
			cnt >= 3 ? puts("Yes") : puts("No");
		}
	}
	return 0;
}