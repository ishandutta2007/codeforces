#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;
typedef long long ll;

int n,m,cnt,k,w,cur;

int main()
{
	scanf("%d%d",&n,&m);
	for(k=1;k <= n;k++){
		cnt += cur;
		if(cnt >= m) break;
		if(!(k&1)) cur++;
	}
	if(cnt < m){
		puts("-1");
		return 0;
	}
	for(int i=1;i < k;i++)
		printf("%d ",i);
	w = k;
	while(cnt > m){
		cnt-- , w += 2;
	}
	printf("%d ",w);
	for(int i=k+1;i <= n;i++)
		printf("%d ",i*10000+1);
	puts("");
	return 0;
}