#include<bits/stdc++.h>
using namespace std;
const int D[4][2]={{1,0},{0,1},{0,-1},{-1,0}};
struct pt{int x,y;bool in(){return 0<=x&&x<=300&&0<=y&&y<=300;}}a[405],P[4],s,t,q[91005];
bool operator==(const pt&a,const pt&b){return a.x==b.x&&a.y==b.y;}
int n,p[91005],way[91005],pre[91005];
bool c[305][305],v[305][305];
bool bfs(){
	q[1]=s,v[s.x][s.y]=1;
	for(int l=1,r=1;l<=r;l++)
		for(int i=0;i<4;i++){
			pt u={q[l].x+D[i][0],q[l].y+D[i][1]};
			if(u.in()&&!v[u.x][u.y]){
				q[++r]=u,way[r]=i,pre[r]=l,v[u.x][u.y]=1;
				if(u==t){
					for(;r>1;r=pre[r])p[++p[0]]=way[r];
					reverse(p+1,p+1+p[0]);
					return 1;
				}
			}
		}
	return 0;
}
bool move(int i){
	s.x+=D[i][0],s.y+=D[i][1];
	t.x+=D[i][0],t.y+=D[i][1];
	putchar("RUDL"[i]);
	if(t.in()&&c[t.x][t.y]){t.x-=D[i][0],t.y-=D[i][1];return 0;}
	return 1;
}
void out(){
	while((0<=s.x&&s.x<=300)||(0<=t.x&&t.x<=300))move(0);
	while((0<=s.y&&s.y<=300)||(0<=t.y&&t.y<=300))move(1);
}
void ud(int d){
	out();
	while((d==2&&t.y>=0)||(d==1&&t.y<=300))move(d);
	while(t.x!=P[d].x)move(t.x<P[d].x?0:3);
	while(t.y!=s.y)move(3-d);
}
void lr(int d){
	out();
	while((d==3&&t.x>=0)||(d==0&&t.x<=300))move(d);
	while(t.y!=P[d].y)move(t.y<P[d].y?1:2);
	while(t.x!=s.x)move(3-d);
}
int main(){
	cin>>s.x>>s.y>>t.x>>t.y>>n;
	if(!n)return puts("-1"),0;
	s.x+=150,s.y+=150,t.x+=150,t.y+=150;
	P[0].x=P[1].y=-1e9,P[2].y=P[3].x=1e9;
	for(int i=1;i<=n;i++){
		cin>>a[i].x>>a[i].y;
		a[i].x+=150,a[i].y+=150;
		v[a[i].x][a[i].y]=c[a[i].x][a[i].y]=1;
		if(a[i].x<P[3].x)P[3]=a[i];
		if(a[i].x>P[0].x)P[0]=a[i];
		if(a[i].y<P[2].y)P[2]=a[i];
		if(a[i].y>P[1].y)P[1]=a[i];
	}
	if(!bfs())return puts("-1"),0;
	for(int i=1;i<=p[0];i++){
		if(move(p[i]))p[++p[0]]=p[i];
		if(s==t)return puts(""),0;
		if(!s.in())break;
	}
	if(s.y<t.y)ud(2);
	if(s.y>t.y)ud(1);
	if(s.x<t.x)lr(3);
	if(s.x>t.x)lr(0);
	puts("");
}