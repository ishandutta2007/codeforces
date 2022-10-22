#include<iostream>
#include<cstdio>
#include<algorithm>
#include<set>
#include<vector>
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
int pos[1000010];
int ans=0x7f7f7f7f;
int n,m;
//map<PII,int>Map;
int query(int x,int y){
	printf("? %d %d\n",x,y);fflush(stdout);
	int a=read();return a;
}
int stk[1000010],top;
void reduce(vector<int>&line,vector<int>&row){
	top=0;
	int n=line.size(),m=row.size();
	if(m==1) return ;
	for(int i:row){
		while(top&&query(line[top-1],stk[top])>=query(line[top-1],i)) --top;
		if(top!=n)stk[++top]=i;
//		printf("top:%d,%d\n",top,stk[top]);
	}
	row.clear();for(int i=1;i<=top;++i) row.pb(stk[i]);
}
void SMAWK(vector<int>line,vector<int>row){
//	printf("SM:\n");for(int i:line) printf("%d ",i);printf("\n");
//	for(int i:row) printf("%d ",i);printf("\n");
	if(line.size()==1){
		int mn=0x7f7f7f7f,p=0;
		for(int i:row){
			int t=query(line[0],i);
			if(t<mn) mn=t,p=i;
		}
		ans=min(ans,mn);pos[line[0]]=p;
		return ;
	}
	
	reduce(line,row);
	vector<int>even;
	for(int i=0;i<line.size();i+=2){
		even.pb(line[i]);
	}
	SMAWK(even,row);
	int it=0;
	for(int i=1;i<line.size();i+=2){
		while(row[it]<pos[line[i-1]]) ++it;
		int mn=0x7f7f7f7f,p=0,pt=0;
		while(it<row.size()&&(i==line.size()-1||row[it]<=pos[line[i+1]])){
			int t=query(line[i],row[it]);
			if(t<mn) mn=t,p=row[it],pt=it;++it;
		}
		pos[line[i]]=p;ans=min(ans,mn);
		it=pt;
	}
}
int main(){
	n=read(),m=read();
	vector<int>a(n),b(m);
	for(int i=1;i<=n;++i) a[i-1]=i;
	for(int i=1;i<=m;++i) b[i-1]=i;
	SMAWK(a,b);
	printf("! %d\n",ans);
	return 0;
}