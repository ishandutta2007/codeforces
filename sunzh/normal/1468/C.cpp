#include<cstdio>
#include<iostream>
#include<queue>
#include<algorithm>
#include<cstring>
#include<set>
#include<vector>
#include<cmath>
#define PII pair<int,int>
#define pb push_back
#define ep emplace_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){ if(c=='-') f=-1; c=getchar();}
	while(c>='0'&&c<='9'){x=(x<<3)+(x<<1)+(c^48);c=getchar();}
	return f==1?x:~x+1;
}
inline void print(int x){
	if(x<0) putchar('-'),x=~x+1;
	if(x>=10) print(x/10);
	putchar((x%10)|48);
}
int q;
bool vis[500010];
int cnt;
priority_queue<PII,vector<PII>,greater<PII> >Q1;
priority_queue<int,vector<int>,greater<int> >Q2;
int main(){
	q=read();
	for(int i=1;i<=q;++i){
		int op=read();
		if(op==1){
			++cnt;
			int x=read();
			Q1.push(mp(-x,cnt));
			Q2.push(cnt);
		}
		else{
			if(op==2){
				int x=Q2.top();
				while(vis[x]){
					Q2.pop();x=Q2.top();
				}
				printf("%d ",x);vis[x]=1;Q2.pop();
			}
			else{
				PII x=Q1.top();
				while(vis[x.se]){
					Q1.pop();x=Q1.top();
				}
				printf("%d ",x.se);vis[x.se]=1;Q1.pop();
			}
		}
	}
}