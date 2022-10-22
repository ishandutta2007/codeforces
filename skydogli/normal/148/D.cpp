#include<bits/stdc++.h>
using namespace std;
#define ld double
bool vis[1005][1005][2];
int w,b;
ld f[1005][1005][2];
ld work(int w,int b,int op){
	if(!w)return op;                                                                    
	if(!b)return 1;
	if(w<0||b<0)return 0;
	if(vis[w][b][op])return f[w][b][op];
	vis[w][b][op]=1;
	int tot=w+b;
	if(!op){
		f[w][b][op]+=(1.0*w)/tot+(1.0*b)/tot*(1.0-work(w,b-1,1));
		return f[w][b][op];
	}
	f[w][b][op]+=(1.0*w)/tot+
		(1.0*b)/tot*
		((1.0*w)/(tot-1)*(1.0-work(w-1,b-1,0))+
		((1.0*(b-1))/(tot-1)*(1-work(w,b-2,0))));
	return f[w][b][op];
}
int main(){
	scanf("%d%d",&w,&b);
	printf("%.11lf",work(w,b,0));
}