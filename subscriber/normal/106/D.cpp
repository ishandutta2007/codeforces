#include<stdio.h>
#include<iostream>
#include<vector>
#include<math.h>
#include<algorithm>
#include<memory.h>
#include<map>
#include<queue>
#include<list>

using namespace std;

int n,m,x,y,up[1111][1111],le[1111][1111],k,cc[111111],dd[111111];
char a[1111][1111];
string ans="";

int main(){
//	freopen("1.in","r",stdin);	
//	freopen("1.out","w",stdout);	
	scanf("%d%d\n",&n,&m);
	for (int i=0;i<n;i++)gets(a[i]);
	for (int i=0;i<m;i++)up[0][i]=(a[0][i]!='#')-1;
	for (int i=1;i<n;i++)for (int j=0;j<m;j++)if (a[i][j]!='#')up[i][j]=up[i-1][j]+1;else up[i][j]=-1;
	for (int i=0;i<n;i++)le[0][i]=(a[0][i]!='#')-1;
	for (int i=0;i<n;i++)for (int j=1;j<m;j++)if (a[i][j]!='#')le[i][j]=le[i][j-1]+1;else le[i][j]=-1;
	scanf("%d\n",&k);
	for (int i=0;i<k;i++)scanf("%c %d\n",&cc[i],&dd[i]);
	for (int i=0;i<n;i++)for (int j=0;j<m;j++)if (a[i][j]>='A'){
		x=i;
		y=j;
		int t=0;
		for (int e=0;e<k;e++){
			if (cc[e]=='N'){
				if (up[x][y]<dd[e])t=1;else x-=dd[e];
			}else if (cc[e]=='S'){
				if (x+dd[e]>=n||up[x+dd[e]][y]<dd[e])t=1;else x+=dd[e];
			}else if (cc[e]=='W'){
				if (le[x][y]<dd[e])t=1;else y-=dd[e];
			}else{
				if (y+dd[e]>=m||le[x][y+dd[e]]<dd[e])t=1;else y+=dd[e];
			}
		}
		if (!t)ans+=a[i][j];
	}
	sort(ans.begin(),ans.end());
	if (ans=="")puts("no solution");else cout << ans << endl;
	return 0;
}