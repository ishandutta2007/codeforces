#include<bits/stdc++.h>
using namespace std;
int T,n,m;
char c[105][105];
int nxt[105];
struct fk{
	int a,b,c,d,e,f;
	fk(int A=0,int B=0,int C=0,int D=0,int E=0,int F=0){
		a=A;b=B;c=C;d=D;e=E;f=F;
	}
};
vector<fk>ans;
int main(){
	scanf("%d",&T);
	while(T--){
		ans.clear();
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;++i){
			scanf("%s",c[i]+1);
			for(int j=1;j<=m;++j)c[i][j]-='0';
		}
		for(int i=1;i<n;++i){
			for(int j=1;j+1<=m;j+=2)
				if(c[i][j]&&!c[i][j+1]){
					if(j!=1){
						ans.push_back(fk(i,j,i+1,j-1,i+1,j));
						c[i][j]^=1;c[i+1][j-1]^=1;c[i+1][j]^=1;
					}
					else{	
						ans.push_back(fk(i,j,i+1,j+1,i+1,j));
						c[i][j]^=1;c[i+1][j+1]^=1;c[i+1][j]^=1;
					}
				}
				else if(!c[i][j]&&c[i][j+1]){
					j++;
					ans.push_back(fk(i,j,i+1,j-1,i+1,j));
					c[i][j]^=1;c[i+1][j-1]^=1;c[i+1][j]^=1;
					j--;
				}
				else if(c[i][j]&&c[i][j+1]){
					ans.push_back(fk(i,j,i,j+1,i+1,j));
					c[i][j]^=1;c[i][j+1]^=1;c[i+1][j]^=1;
				}
			if(c[i][m]){
				ans.push_back(fk(i,m,i+1,m-1,i+1,m));
				c[i][m]^=1;c[i+1][m-1]^=1;c[i+1][m]^=1;	
			}
		}

		nxt[m+1]=m+1;
		for(int i=m;i;--i)
			if(!c[n][i])nxt[i]=i;
			else nxt[i]=nxt[i+1];

		for(int i=1;i+1<=m;i+=2){
			if(c[n][i]&&c[n][i+1]){
				if(c[n][i+2]&&i+2<=m&&(nxt[i]-i)%2==1){
					c[n][i]=c[n][i+1]=c[n][i+2]=0;
					ans.push_back(fk(n-1,i+1,n,i,n,i+1));
					ans.push_back(fk(n-1,i+1,n-1,i+2,n,i+1));
					ans.push_back(fk(n-1,i+2,n,i+1,n,i+2));
					i++;
					continue;
				}
				c[n][i]=c[n][i+1]=0;
				ans.push_back(fk(n-1,i,n-1,i+1,n,i+1));
				ans.push_back(fk(n-1,i,n,i,n-1,i+1));
			}
			else if(c[n][i]&&!c[n][i+1]){
				if(c[n][i+2]&&i+2<=m){
					c[n][i+2]=c[n][i]=0;
					ans.push_back(fk(n-1,i+1,n,i,n,i+1));
					ans.push_back(fk(n-1,i+1,n,i+1,n,i+2));
					continue;
				}
				ans.push_back(fk(n-1,i,n,i,n,i+1));
				ans.push_back(fk(n-1,i+1,n,i,n,i+1));
				ans.push_back(fk(n-1,i,n-1,i+1,n,i));
				c[n][i]=0;
			}
			else if(!c[n][i]&&c[n][i+1]){
				if(i+1!=m&&c[n][i+2]){i--;continue;}
				ans.push_back(fk(n-1,i+1,n,i,n,i+1));
				ans.push_back(fk(n-1,i,n-1,i+1,n,i+1));
				ans.push_back(fk(n-1,i,n,i,n,i+1));
				c[n][i+1]=0;
			}
		}
		int i=m-1;

			if(!c[n][i]&&c[n][i+1]){

				ans.push_back(fk(n-1,i+1,n,i,n,i+1));
				ans.push_back(fk(n-1,i,n-1,i+1,n,i+1));
				ans.push_back(fk(n-1,i,n,i,n,i+1));
			}
		printf("%d\n",(int)ans.size());
		for(int i=0;i<ans.size();++i){
			printf("%d %d %d %d %d %d\n",ans[i].a,ans[i].b,ans[i].c,ans[i].d,ans[i].e,ans[i].f);
		}
	}
	return 0;
}