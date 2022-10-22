#include<bits/stdc++.h>
using namespace std;
#define MN 1000015
int n,m,ch[MN],vis[MN],ok[MN];
inline int id(int x,int y){
	return (x-1)*m+y;
}
struct P{
	int x,y;
	P(int X=0,int Y=0){x=X;y=Y;}
};
queue<P>Q;
void bfs(){
	Q.push(P(n,m));
	ok[id(n,m)]=1;
	while(!Q.empty()){
		P w=Q.front();
		Q.pop();
		int x=w.x,y=w.y;
//		cout<<"OK "<<x<<" "<<y<<endl;
		if(x>1&&!ok[id(x-1,y)]&&ch[id(x-1,y)]!='#'){
			Q.push(P(x-1,y));
			ok[id(x-1,y)]=1;
		}
		if(y>1&&!ok[id(x,y-1)]&&ch[id(x,y-1)]!='#'){
			Q.push(P(x,y-1));
			ok[id(x,y-1)]=1;
		}
	}
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j){
			int now=id(i,j);
			ch[now]=getchar();
			while(ch[now]!='.'&&ch[now]!='#')ch[now]=getchar();
		}
	bfs();
	while(!Q.empty())Q.pop();
	Q.push(P(1,1));
	int ans=3;
	while(!Q.empty()){
		P w=Q.front();
		Q.pop();
		int x=w.x,y=w.y;
//		cout<<"OK "<<x<<" "<<y<<endl;
		if(x<n&&!vis[id(x+1,y)]&&ok[id(x+1,y)]&&ch[id(x+1,y)]!='#'){
			Q.push(P(x+1,y));
			vis[id(x+1,y)]=1;
		}
		if(y<m&&!vis[id(x,y+1)]&&ok[id(x,y+1)]&&ch[id(x,y+1)]!='#'){
			Q.push(P(x,y+1));
			vis[id(x,y+1)]=1;
		}
		if(vis[id(n,m)]) {break;}
		ans=min(ans,(int)Q.size());
	}
	printf("%d",ans);
	return 0;
}