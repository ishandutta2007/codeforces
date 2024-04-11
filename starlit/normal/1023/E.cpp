#include<bits/stdc++.h>
#define N 503
using namespace std;
char res[5];
int n;
bool fla;
inline bool qry(int x,int y){
	if(x>n||y>n)return 0;
	printf("? ");
	if(fla)printf("1 1 %d %d\n",x,y);
	else printf("%d %d %d %d\n",x,y,n,n);
	fflush(stdout);
	scanf("%s",res);
	assert(res[0]^'B');
	return res[0]=='Y';
}
int x=1,y=1,ans[N<<1],t;
int main(){
	scanf("%d",&n);
	for(;;){
		if(n<x+y){fla=1;break;}
		if(qry(x+1,y))ans[t++]=1,x++;
		else ans[t++]=-1,y++;
	}
	t=n-1<<1,x=y=n;
	for(;;){
		if(x+y<=n+1)break;
		if(qry(x,y-1))ans[--t]=-1,y--;
		else ans[--t]=1,x--;
	}
	printf("! ");
	for(int i=0;i<n-1<<1;i++)putchar(ans[i]>0?'D':'R');
	fflush(stdout);
}