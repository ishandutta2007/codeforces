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
int n;
int a[500010];
int Q;
struct base{
	int base[22];
	int id[22];
	void insert(int pos,int x){
		for(int i=20;i>=0;--i){
			if(!(x&(1<<i))) continue ;
			if(!base[i]){
				base[i]=x;id[i]=pos;break ;
			}
			else if(id[i]<pos){
				swap(id[i],pos);swap(base[i],x);
			}
			x^=base[i];
		}
	}
	int check(int pos){
		int ans=0;
		for(int i=20;i>=0;--i){
			if(id[i]>=pos&&ans<(ans^base[i])) ans^=base[i];
		}
		return ans;
	}
}res[500010];
int main(){
	n=read();
	for(int i=1;i<=n;++i) a[i]=read();
	for(int i=1;i<=n;++i){
		res[i]=res[i-1];
		res[i].insert(i,a[i]);
	}
	Q=read();
	while(Q--){
		int l=read(),r=read();
		printf("%d\n",res[r].check(l));
	}
	return 0;
}