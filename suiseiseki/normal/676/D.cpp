#include<cstdio>  
#include<cstring>  
#include<cstdlib>  
#include<cmath>  
#include<iostream>  
#include<algorithm>  
#include<vector>  
#include<map>  
#include<set>  
#include<queue>  
#include<string>  
#include<bitset>  
#include<utility>  
#include<functional>  
#include<iomanip>  
#include<sstream>  
#include<ctime>  
using namespace std;  
 
#define maxn int(1e3+20)  
#define inf int(0x3f3f3f3f) 
#define mod int(1e9+7)
#define PI acos(-1.0)
typedef long long ll;
char c;
int g[maxn][maxn],n,m;
struct Point
{
	int u,v,time,state;
	Point(){time = 0;};
	Point(int _u, int _v, int _time, int _state):u(_u),v(_v),time(_time),state(_state){}
}s,t;
int fun(char x)
{
	switch(x)
	{
	case '^': return 8;break;
	case 'v': return 2;break;
	case '<': return 1;break;
	case '>': return 4;break;
	case '+': return 15;break;
	case '-': return 5;break;
	case '|': return 10;break;
	case 'L': return 14;break;
	case 'R': return 11;break;
	case 'U': return 7;break;
	case 'D': return 13;break;
	case '*': return 0;break;
	}
}
int dir[4][2] ={{0,-1},{1,0},{0,1},{-1,0}};
bool vis[maxn][maxn][5];
int bfs()
{
	memset(vis,0,sizeof(vis));
	queue<Point>q;
	Point next,head;
	q.push(s);
	vis[s.u][s.v][s.state] = 1;
	while(!q.empty())
	{
		head = q.front(); q.pop();
		if(head.u == t.u && head.v == t.v){
			return head.time;
		}
		if(!vis[head.u][head.v][(head.state+1)%4]){
			q.push(Point(head.u, head.v,head.time +1,(head.state+1)%4));
			vis[head.u][head.v][(head.state+1)%4] = 1;
		}
		for(int i = 0; i<4; i++)
		{
 
			next.u = head.u + dir[i][0];
 			next.v = head.v + dir[i][1];
			if(g[next.u][next.v] != 0)
			{
				next.state = head.state;
				if(next.u >= 1 && next.u <= n && next.v >= 1 && next.v<= m && g[head.u][head.v] & ((1<<(i+next.state)%4))
					&& g[next.u][next.v] & ((1<<(i+next.state+2)%4))){	
					if(!vis[next.u][next.v][next.state]){
						next.time = head.time + 1;
						q.push(next);
						vis[next.u][next.v][next.state] = 1;
					}
				}
			}
		}
	}
	return -1;
}
int main()  
{   
	while(~scanf("%d%d",&n,&m))
	{
		for(int i = 1; i<=n; i++){
			for(int j = 1; j<=m; j++){
				scanf(" %c",&c);
				g[i][j] = fun(c);
			}
		}
		scanf("%d%d",&s.u,&s.v);
		scanf("%d%d",&t.u,&t.v);
		s.state = t.state = 0;
		printf("%d\n",bfs());
	}
	return 0;                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                            
}