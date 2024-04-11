#include<bits/stdc++.h>
using namespace std;

struct fe{
	int x,y;
}qu[100005];
const int d[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
int n,m,p,q,top,b[255][255];
char s[255][255];
long long a[255][255];
int main(){
	scanf("%d%d%d%d",&n,&m,&p,&q);
	for(int i=0;i<n;i++)scanf("%s",s[i]);
	for(int i=0;i<n;i++)for(int j=0;j<m;j++)if(s[i][j]>='A'&&s[i][j]<='Z'){
		top=1;qu[0]=(fe){i,j};b[i][j]=(s[i][j]-'A'+1)*p;
		for(int k=0;k<top;k++){
			int x=qu[k].x,y=qu[k].y,z=b[x][y]>>1;
			a[x][y]+=b[x][y];
			if(z)for(int i=0;i<4;i++){
				int nx=x+d[i][0],ny=y+d[i][1];
				if(nx>=0&&nx<n&&ny>=0&&ny<m&&!b[nx][ny]&&s[nx][ny]!='*'){
					b[nx][ny]=z;qu[top++]=(fe){nx,ny};
				}
			}
		}
		for(int k=0;k<top;k++)b[qu[k].x][qu[k].y]=0;
	}
	int ans=0;
	for(int i=0;i<n;i++)for(int j=0;j<m;j++)if(a[i][j]>q)ans++;
	printf("%d\n",ans);
	return 0;
}