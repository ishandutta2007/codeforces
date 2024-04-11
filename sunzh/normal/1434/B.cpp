#include<cstdio>
#include<iostream>
#include<queue>
#include<algorithm>
#include<cstring>
#include<set>
#include<vector>
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


int n;
int stk[100005],top;
int tag[100005],idx;
bool f[100005];
int cnt[100005];
void failed(){
	puts("NO");exit(0);
}
int main(){
	n=read();
	for(int i=1;i<=(n<<1);++i){
		char c=getchar();
		while(c!='-'&&c!='+') c=getchar();
		if(c=='+') stk[++top]=++idx;
		else{
			int x=read();
			if(top==0||f[x]) failed();
			f[x]=1;
			if(tag[stk[top]]>x) failed();
			tag[stk[top]]=x;
			--top;
			tag[stk[top]]=max(tag[stk[top]],tag[stk[top+1]]);
		}
	}
	for(int i=1;i<=n;++i) ++cnt[tag[i]];
	for(int i=n;i>0;--i){
		cnt[i]+=cnt[i+1];
		if(cnt[i]>n-i+1) failed();
	} 
	printf("YES\n");
	for(int i=1;i<=n;++i) print(tag[i]),putchar(' ');
}