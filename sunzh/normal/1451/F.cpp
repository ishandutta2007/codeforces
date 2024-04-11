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
#define pow powl
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
int a[210][210];
int main(){
	T=read();
	while(T--){
		n=read(),m=read();memset(a,0,sizeof(a));
		for(int i=1;i<=n;++i)
			for(int j=1;j<=m;++j) a[i][j]=read();int f=1;
		for(int i=2;i<=n+m;++i){
			int s=0,flg=0;
			for(int j=1;j<i;j++){
				int k=i-j;
				if(a[j][k])flg=1;
				s^=a[j][k];
			}
			if(s)f=0;
		}
		if(f)cout<<"Jeel"<<endl;
		else cout<<"Ashish"<<endl;
	}
}