#include <stack>
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

int gint(){
	char c; int f=1;
	while(c=getchar(),c<48||c>57)
		if(c=='-')f=-1;
	int x=0;
	for(;c>47&&c<58;c=getchar()){
		x=x*10+c-48;
	}
	return x*f;
}

#define max_S 65535
typedef pair<int,int>pii;

stack<pii>st;

bool map[3001][6001];

int f[3000*6100];

int r,c,n,ans;

int find(int x){
	if(x==f[x])return x;
	st.push(pii(x,f[x]));
	return f[x]=find(f[x]);
}

const int dx[]={0,0,1,-1,1,-1,1,-1};
const int dy[]={1,-1,0,0,1,-1,-1,1};

inline bool check(int x,int y){
	map[x][y]=map[x][y+c]=1;
	int F=find(x*6001+y);
	for(int i=0,x1,y1;i<8;++i){
		x1=x+dx[i],y1=y+dy[i];
		if(!x1||x1>r)continue;
		if(!y1)y1=2*c;
		if(!map[x1][y1])continue;
		int f1=find(x1*6001+y1);
		if(F==f1)continue;
		st.push(pii(f1,f1));
		f[f1]=F;
	}
	F=find(x*6001+y+c);
	for(int i=0,x1,y1;i<8;++i){
		x1=x+dx[i],y1=y+c+dy[i];
		if(!x1||x1>r)continue;
		if(y1==2*c+1)y1=1;
		if(!map[x1][y1])continue;
		int f1=find(x1*6001+y1);
		if(F==f1)continue;
		st.push(pii(f1,f1));
		f[f1]=F;
	}
	if(find(x*6001+y+c)!=find(x*6001+y)){
		while(!st.empty())st.pop();
		return 1;
	}
	while(!st.empty())f[st.top().first]=st.top().second,st.pop();
	map[x][y]=map[x][y+c]=0;
	return 0;
}

int main(){
	r=gint(),c=gint();
	for(int i=1;i<=r;++i)for(int j=1;j<=2*c;++j)f[i*6001+j]=i*6001+j;
	n=gint();
	for(int i=1,x,y;i<=n;++i){
		x=gint(),y=gint(),ans+=check(x,y);
	}
	return printf("%d\n",ans),0;
}