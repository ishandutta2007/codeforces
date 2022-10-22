#include<iostream>
#include<cstdio>
#include<algorithm>
#include<set>
#include<vector>
#include<random>
#include<ctime>
#include<cstring>
#include<map>
#include<queue>
#define mp make_pair
#define PII pair<int,int>
#define fi first
#define se second
#define pb push_back
using namespace std;
inline int read(){
	int x=0,f=1;
	char c=getchar();
	while(!isdigit(c)){if(c=='-') f=-1;c=getchar();}
	while(isdigit(c)){x=(x<<3)+(x<<1)+(c^48);c=getchar();}
	return f==1?x:~x+1;
}
int n,m;
vector<int>vec[250010];
void getas(vector<int>x){
	for(int i=1;i<=n;++i){
		int cnt=0;
		for(int j=1;j<=m;++j){
			if(vec[i][j]!=x[j]) ++cnt;
		}
		if(cnt>2)return ;
	}
	printf("Yes\n");
	for(int i=1;i<=m;++i) printf("%d ",x[i]);
	exit(0);
}
void chk(vector<int>std,int pos){
	std[pos]=-1;
	for(int i=1;i<=n;++i){
		int df=0;
		for(int j=1;j<=m;++j) if(vec[i][j]!=std[j]) ++df;
		if(df>3) return ;
		if(df<=2) continue ;
		if(std[pos]==-1) std[pos]=vec[i][pos];
		else if(df==3) return ;
	}
	printf("Yes\n");
	for(int i=1;i<=m;++i) printf("%d ",std[i]==-1?vec[1][i]:std[i]);
	exit(0);
}
void check(int x,int cnt){
	vector<int>dif;
	for(int i=1;i<=m;++i){
		if(vec[x][i]!=vec[1][i]) dif.pb(i);
	}
	vector<int>ans(m+1);
	for(int i=1;i<=m;++i){
		ans[i]=vec[1][i];
	}
	if(cnt==3){
		for(int i=0;i<2;++i){
			for(int j=i+1;j<3;++j){
				int k=i^j^3;
				ans[dif[i]]=vec[x][dif[i]];
				chk(ans,dif[k]);
				ans[dif[i]]=vec[1][dif[i]];
				
				ans[dif[j]]=vec[x][dif[j]];
				chk(ans,dif[k]);
				ans[dif[j]]=vec[1][dif[j]];
			}
		}
	}
	else{
		
		ans[dif[0]]=vec[x][dif[0]];
		ans[dif[1]]=vec[x][dif[1]];
		getas(ans);
		ans[dif[0]]=vec[1][dif[0]];
		ans[dif[1]]=vec[1][dif[1]];
		
		ans[dif[0]]=vec[x][dif[0]];
		ans[dif[2]]=vec[x][dif[2]];
		getas(ans);
		ans[dif[0]]=vec[1][dif[0]];
		ans[dif[2]]=vec[1][dif[2]];
		
		ans[dif[0]]=vec[x][dif[0]];
		ans[dif[3]]=vec[x][dif[3]];
		getas(ans);
		ans[dif[0]]=vec[1][dif[0]];
		ans[dif[3]]=vec[1][dif[3]];
		
		ans[dif[1]]=vec[x][dif[1]];
		ans[dif[2]]=vec[x][dif[2]];
		getas(ans);
		ans[dif[1]]=vec[1][dif[1]];
		ans[dif[2]]=vec[1][dif[2]];
		
		ans[dif[3]]=vec[x][dif[3]];
		ans[dif[1]]=vec[x][dif[1]];
		getas(ans);
		ans[dif[3]]=vec[1][dif[3]];
		ans[dif[1]]=vec[1][dif[1]];
		
		ans[dif[3]]=vec[x][dif[3]];
		ans[dif[2]]=vec[x][dif[2]];
		getas(ans);
		ans[dif[3]]=vec[1][dif[3]];
		ans[dif[2]]=vec[1][dif[2]];
		
	}
	printf("No\n");
	exit(0);
}
int main(){
	n=read(),m=read();
	for(int i=1;i<=n;++i) vec[i].assign(m+1,0);
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j) vec[i][j]=read();
	}
	for(int i=2;i<=n;++i){
		int cnt=0;
		for(int j=1;j<=m;++j){
			if(vec[i][j]!=vec[1][j]) ++cnt;
		}
		if(cnt>=5){
			printf("No\n");exit(0);
		}
		else if(cnt>=3){
			check(i,cnt);
			break ;
		}
	}
	printf("Yes\n");
	for(int i=1;i<=m;++i) printf("%d ",vec[1][i]);
	printf("\n");
}