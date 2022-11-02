#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const int N = 110;
int n,c[N][N],t,x,y,xx,yy;
struct osc{
	int x,y;
	osc(int xx=0,int yy=0){x = xx , y = yy;}
};
stack<osc>q,qq;

int main()
{
	scanf("%d",&n);
	for(int i=1;i <= n;i++) for(int j=1;j <= n;j++) 
		if((i+j)&1) q.push(osc(i,j));
		else qq.push(osc(i,j));
	for(int i=1;i <= n*n;i++){
		scanf("%d",&t);
		if(t != 1){
			if(!q.empty()){
				osc x = q.top(); q.pop();
				printf("1 %d %d\n",x.x,x.y);
				fflush(stdout);
			}
			else{
				osc x = qq.top(); qq.pop();
				printf("%d %d %d\n",t == 2 ? 3 : 2,x.x,x.y);
				fflush(stdout);
			}
		}
		else{
			if(!qq.empty()){
				osc x = qq.top(); qq.pop();
				printf("2 %d %d\n",x.x,x.y);
				fflush(stdout);
			}
			else{
				osc x = q.top(); q.pop();
				printf("%d %d %d\n",t == 1 ? 3 : 1,x.x,x.y);
				fflush(stdout);
			}
		}
	}
}