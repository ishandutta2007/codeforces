#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const int N = 1550;
//I understand le !

int n,m,a[N][N],b[N][N],vis[N],ans[N],cnt,h[N];

int *x[N];

inline int cmp(int *x,int *y){
	for(int i=1;i <= cnt;i++){
		if(x[ans[i]] < y[ans[i]]) return 1;
		if(x[ans[i]] > y[ans[i]]) return 0;
	}
	return 0;
}

set<int>s[N];
set<int>::iterator it;

queue<int>q;

inline int check(){
	for(int i=1;i <= n;i++) for(int j=1;j <= m;j++) if(x[i][j] != b[i][j]) return 0;
	return 1;
}

inline int getint(){
	int xx = 0;
	char ch = getchar();
	while(ch < '0' || ch > '9') ch = getchar();
	while(ch >= '0' && ch <= '9'){
		xx = (xx<<3)+(xx<<1)+ch-48;
		ch = getchar();
	}
	return xx;
}

int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i <= n;i++) for(int j=1;j <= m;j++) a[i][j] = getint();
	for(int i=1;i <= n;i++) for(int j=1;j <= m;j++) b[i][j] = getint();
	for(int j=1;j <= m;j++)
		for(int i=1;i < n;i++) if(b[i][j] > b[i+1][j]) s[j].insert(i);
	for(int i=1;i <= m;i++) if(s[i].empty()) q.push(i);
//	for(int i=1;i <= n;i++) h[i] = m;
	while(!q.empty()){
		int x = q.front(); q.pop();
		ans[++cnt] = x; //h[x] = cnt;
		for(int i=1;i < n;i++) if(b[i][x] < b[i+1][x] && !vis[i]){
			vis[i] = 1;
			for(int j=1;j <= m;j++) if(!s[j].empty()){
				s[j].erase(i);
				if(s[j].empty()) q.push(j);
			}
		}
	}
	for(int i=1;i <= n;i++) x[i] = a[i];
	stable_sort(x+1,x+1+n,cmp);
	if(check()){
		printf("%d\n",cnt);
		for(int i=cnt;i >= 1;i--) printf("%d ",ans[i]);
		puts("");
	}
	else puts("-1");
	return 0;
}