#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

const int N = 1e5+10;

int n,head[N],top,ans,d[N],vis[2];
struct cyb{
	int to,next;
}a[N<<1];

inline void add(int f,int t){
	a[++top].to = t;
	a[top].next = head[f];
	head[f] = top;
	a[++top].to = f;
	a[top].next = head[t];
	head[t] = top;
}

void dfs(int x,int f,int dp){
	int cnt = -1;
	for(int i=head[x];i != -1;i = a[i].next)
		if(a[i].to != f){
			if(d[a[i].to] == 1)
				vis[dp&1] = 1 , cnt++;
			else
				dfs(a[i].to,x,dp+1);
		}
	if(cnt>0) ans -= cnt;
}

int main()
{
	memset(head,-1,sizeof(head));
	scanf("%d",&n);ans = n-1;
	int f,t;
	for(int i=1;i < n;i++)
		scanf("%d%d",&f,&t) , d[f]++ , d[t]++ , add(f,t);
	for(int i=1;i <= n;i++){
		if(d[i] != 1){
			dfs(i,0,1) ;break;
		}
	}
	if(vis[0] && vis[1]) printf("3 ");
	else printf("1 ");
	printf("%d\n",ans);
	return 0;
}