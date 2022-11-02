#include <bits/stdc++.h>
#define inf 0x3f3f3f3f
#define x first
#define y second
using namespace std;
typedef long long INT;
typedef pair<int,int> pii;
#define NN 1010
char s[NN][NN];
int dst[NN][NN][5];
int vst[NN][NN];
int d[NN][NN];
int n,m;
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
bool out(int u,int v){
	return u<=n&&u>=1&&v<=m&&v>=1;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
#endif
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%s",s[i]+1);
	for(int k=1;k<=3;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				if(s[i][j]-'0'==k) dst[i][j][k]=0;
				else dst[i][j][k]=inf;
			}
		}
	}
	for(int k=1;k<=3;k++){
		queue<pii> q;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				vst[i][j]=0;
				if(s[i][j]-'0'==k){
					q.push(pii(i,j));
					vst[i][j]=1;
				}
			}
		}
		while(!q.empty()){
			pii u=q.front();
			q.pop();
			for(int i=0;i<4;i++){
				int uu=u.x+dx[i];
				int vv=u.y+dy[i];
				if(out(uu,vv)==0||vst[uu][vv]==1||s[uu][vv]=='#') continue;
				dst[uu][vv][k]=dst[u.x][u.y][k]+1;
				vst[uu][vv]=1;
				q.push(pii(uu,vv));
			}
		}
	}
	INT ans=inf;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			INT val=(INT)dst[i][j][1]+dst[i][j][2]+dst[i][j][3]-2;
			ans=min(ans,val);
		}
	}
	INT dst12=inf,dst23=inf,dst31=inf;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(s[i][j]=='1') dst12=min(dst12,(INT)dst[i][j][2]);
			if(s[i][j]=='2') dst23=min(dst23,(INT)dst[i][j][3]);
			if(s[i][j]=='3') dst31=min(dst31,(INT)dst[i][j][1]);
		}
	}
	ans=min(ans,dst12+dst31-2);
	ans=min(ans,dst12+dst23-2);
	ans=min(ans,dst31+dst23-2);
	if(ans>=inf/2) puts("-1");
	else printf("%I64d\n",ans);
    return 0;
}