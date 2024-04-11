#include<bits/stdc++.h>
using namespace std;
#define ri register int
#define DEBUG(k...) fprintf(stderr,k)
typedef long long ll;
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,true:false;}
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,true:false;}
const int d[4][2]={{0,1},{1,0},{0,-1},{-1,0}},maxn=1e6+10;
vector<bool>ans[maxn];
string s[maxn];
int a[maxn],m,n,sx,sy,t_case;
inline bool check(int x,int y){
	return x>=0&&x<n&&y>=0&&y<m;
}
inline int calc(int x,int y){
	ri ret=0;
	for(ri i=0;i<4;++i){
		ri mx=x+d[i][0],my=y+d[i][1];
		if(check(mx,my)&&!ans[mx][my])ret+=(s[mx][my]=='L'||s[mx][my]=='.');
	}
	return ret;
}
int main(){
	scanf("%d",&t_case);
	while(t_case--){
		scanf("%d%d",&n,&m);
		for(ri i=0;i<n;++i){
			ans[i].resize(m);
			cin>>s[i];
			for(ri j=0;j<m;++j){
				ans[i][j]=false;
				if(s[i][j]=='L')sx=i,sy=j;
			}
		}
		typedef pair<int,int> pii;
		#define fi first
		#define se second
		queue<pii>q;
		q.push({sx,sy});
		while(q.size()){
			pii p=q.front();q.pop();
			ans[p.fi][p.se]=true;
			for(ri i=0;i<4;++i){
				ri mx=p.fi+d[i][0],my=p.se+d[i][1];
				if(check(mx,my)){
					if(ans[mx][my]||s[mx][my]!='.')continue;
					if(calc(mx,my)<=1)q.push({mx,my});
				}
			}
		}
		for(ri i=0;i<n;++i,putchar(10))
			for(ri j=0;j<m;++j)
				if(s[i][j]=='.')putchar(ans[i][j]?'+':'.');
				else putchar(s[i][j]);
	}
	return 0;
}