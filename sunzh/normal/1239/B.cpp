#include<cstdio>
#include<iostream>
#include<queue>
#include<algorithm>
#include<cstring>
#include<set>
#include<vector>
#include<cmath>
#include<stack>
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
int stk[300010];
int top;
int n;
char str[300010];
char s[300010];
int cnt[300010],R[300010];
int fa[300010];
int p[300010];
int main(){
	n=read();
	scanf("%s",str+1);
	int cntl,cntr;cntl=cntr=0;
	for(int i=1;i<=n;++i) if(str[i]=='(') ++cntl;else ++cntr;
	if(cntl!=cntr){
		printf("0\n1 1\n");return 0;
	}
	int minn=0,tmp=0,pos=0;
	for(int i=1;i<=n;++i){
		if(str[i]==')') --tmp;
		else ++tmp;
		if(tmp<minn) minn=tmp,pos=i;
	}
	int P=0;
	for(int i=pos+1;i<=n;++i) s[++P]=str[i],p[P]=i;
	for(int i=1;i<pos+1;++i) s[++P]=str[i],p[P]=i;
	for(int i=1;i<=n;++i){
		if(s[i]=='('){
			fa[i]=stk[top];stk[++top]=i;
		}
		else{
			R[stk[top]]=i;
			--top;
			++cnt[stk[top]];
		}
	}
	int ans=cnt[0];
	int sl,sr;
	sl=1,sr=1;
	auto Max=[&](int &x,int y,int id){
		if(y>x){
			x=y;sl=id,sr=R[id];
		}
		return ;
	};
	for(int i=1;i<=n;++i){
		if(s[i]=='('){
			if(!fa[i]) Max(ans,cnt[i]+1,i);
			else if(!fa[fa[i]])Max(ans,cnt[0]+cnt[i]+1,i);
		}
	}
	printf("%d\n%d %d\n",ans,p[sl],p[sr]);
}