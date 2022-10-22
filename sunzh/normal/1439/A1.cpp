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
	return f==1?x:-x;
}
inline void print(int x){
	if(x<0) putchar('-'),x=~x+1;
	if(x>=10) print(x/10);
	putchar((x%10)|48);
}
int T;
int n,m;
bool Map[110][110];
char str[110];
int ans;
vector<vector<PII> >opt;
void soli(int i,int j){
	if(Map[i+2][j+1]&&Map[i+2][j]){
		++ans;Map[i+2][j+1]^=1;Map[i+2][j]^=1;Map[i+1][j]^=1;
		vector<PII>v;v.ep(i+2,j+1);v.ep(i+2,j);v.ep(i+1,j);
		opt.ep(v);
	}
	else if(Map[i+2][j+1]){
		++ans;Map[i+2][j+1]^=1;Map[i+1][j+1]^=1;Map[i+1][j]^=1;
		vector<PII>v;v.ep(i+2,j+1);v.ep(i+1,j+1);v.ep(i+1,j);
		opt.ep(v);
	}
	else if(Map[i+2][j]){
		++ans;Map[i+2][j]^=1;Map[i+1][j]^=1;Map[i+1][j+1]^=1;
		vector<PII>v;v.ep(i+2,j);v.ep(i+1,j);v.ep(i+1,j+1);
		opt.ep(v);
	}
}
void solj(int i,int j){
	if(Map[i+1][j+2]&&Map[i][j+2]){
		++ans;Map[i+1][j+2]^=1;Map[i][j+2]^=1;Map[i][j+1]^=1;
		vector<PII>v;v.ep(i+1,j+2);v.ep(i,j+2);v.ep(i,j+1);
		opt.ep(v);
	}
	else if(Map[i+1][j+2]){
		++ans;Map[i+1][j+2]^=1;Map[i+1][j+1]^=1;Map[i][j+1]^=1;
		vector<PII>v;v.ep(i+1,j+2);v.ep(i+1,j+1);v.ep(i,j+1);
		opt.ep(v);
	}
	else if(Map[i][j+2]){
		++ans;Map[i][j+2]^=1;Map[i][j+1]^=1;Map[i+1][j+1]^=1;
		vector<PII>v;v.ep(i,j+2);v.ep(i,j+1);v.ep(i+1,j+1);
		opt.ep(v);
	}
}
void solve(int x,int y){
	if(Map[x][y]){
		++ans;Map[x][y]^=1;Map[x+1][y]^=1;Map[x][y+1]^=1;
		vector<PII>v;v.ep(x,y);v.ep(x+1,y);v.ep(x,y+1);
		opt.ep(v);
	}
	int s=Map[x+1][y]+Map[x][y+1]+Map[x+1][y+1];
	if(s==0) return ;
	if(s==1){
		if(Map[x+1][y]){
			++ans;
			vector<PII>v;v.ep(x+1,y);v.ep(x+1,y+1),v.ep(x,y+1);opt.ep(v);
			v.clear();
			++ans;
			v.ep(x,y);v.ep(x+1,y);v.ep(x+1,y+1);
			opt.ep(v);v.clear();
			++ans;v.ep(x,y),v.ep(x+1,y);v.ep(x,y+1);opt.ep(v);
		}
		else if(Map[x][y+1]){
			++ans;
			vector<PII>v;v.ep(x+1,y);v.ep(x+1,y+1),v.ep(x,y+1);opt.ep(v);
			v.clear();
			++ans;
			v.ep(x,y);v.ep(x,y+1);v.ep(x+1,y+1);
			opt.ep(v);v.clear();
			++ans;v.ep(x,y),v.ep(x+1,y);v.ep(x,y+1);opt.ep(v);
		}
		else{
			++ans;
			vector<PII>v;v.ep(x+1,y);v.ep(x+1,y+1),v.ep(x,y);opt.ep(v);
			v.clear();
			++ans;v.ep(x+1,y);v.ep(x,y+1);v.ep(x+1,y+1);opt.ep(v);
			v.clear();
			++ans;v.ep(x,y);v.ep(x,y+1);v.ep(x+1,y+1);opt.ep(v);
		}
	}
	else if(s==2){
		vector<PII>v;
		if(Map[x+1][y]&&Map[x][y+1]){
			++ans;v.ep(x+1,y);v.ep(x,y+1);v.ep(x+1,y+1);opt.ep(v);v.clear();
			++ans;
			v.ep(x+1,y);v.ep(x+1,y+1),v.ep(x,y);opt.ep(v);
			v.clear();
			++ans;v.ep(x+1,y);v.ep(x,y+1);v.ep(x+1,y+1);opt.ep(v);
			v.clear();
			++ans;v.ep(x,y);v.ep(x,y+1);v.ep(x+1,y+1);opt.ep(v);
			
		}
		else if(Map[x+1][y]&&Map[x+1][y+1]){
			++ans;v.ep(x,y);v.ep(x+1,y);v.ep(x,y+1);opt.ep(v);v.clear();
			++ans;v.ep(x,y);v.ep(x,y+1);v.ep(x+1,y+1);opt.ep(v);v.clear();
		}
		else{
			++ans;v.ep(x,y);v.ep(x+1,y);v.ep(x,y+1);opt.ep(v);v.clear();
			++ans;v.ep(x,y);v.ep(x+1,y);v.ep(x+1,y+1);opt.ep(v);v.clear();
		}
	}
	else{
		++ans;vector<PII>v;v.ep(x+1,y),v.ep(x,y+1),v.ep(x+1,y+1);opt.ep(v);
	}
	Map[x+1][y]=Map[x][y+1]=Map[x+1][y+1]=0;
}
int main(){
	T=read();
	while(T--){
		ans=0;opt.clear();
		n=read(),m=read();
		for(int i=1;i<=n;++i){
			scanf("%s",str+1);
			for(int j=1;j<=m;++j) Map[i][j]=str[j]-'0';
		}
		for(int i=1;i<=n;i+=2){
			for(int j=1;j<=m;j+=2){
				if(n-i+1==3){
					if(m-j+1==3){
						if(Map[i+2][j+2]){
							++ans;Map[i+2][j+2]^=1;Map[i+2][j+1]^=1;Map[i+1][j+2]^=1;
							vector<PII>v;v.ep(i+2,j+2);v.ep(i+2,j+1);v.ep(i+1,j+2);
							opt.ep(v);
						}
						soli(i,j);solj(i,j);
					}
					else{
						soli(i,j);
					}
				}
				else{
					if(m-j+1==3){
						solj(i,j);
					}
				}
				solve(i,j);
			}
		}
		printf("%d\n",ans);
		for(auto v:opt){
			for(auto i:v) printf("%d %d ",i.fi,i.se);
			printf("\n");
		}
	}
	return 0;
}