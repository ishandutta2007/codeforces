/*
ID: Sfiction
OJ: CF
PROB: 451B
*/
#include <cstdio>

const int MAXN=1E5+10;
const int INF=1<<30;

int n;
int a[MAXN];
int list[2];

int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;++i)
		scanf("%d",&a[i]);
	a[0]=-1;
	a[n+1]=INF;

	int cnt=0;
	for (int i=1;i<=n;++i)
		if ((a[i-1] < a[i]) != (a[i] < a[i+1])){
			if (cnt==2){
				++cnt;
				break;
			}
			list[cnt++]=i;
		}
	if (cnt==0)
		puts("yes\n1 1");
	else if (cnt == 2 && a[list[0]] < a[list[1]+1] && a[list[0]-1] < a[list[1]])
		printf("yes\n%d %d",list[0],list[1]);
	else
		puts("no");

	return 0;
}