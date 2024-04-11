#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
#include<map>
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();
	while(c<'0'||c>'9') { if(c=='-') f=-1; c=getchar();}
	while(c>='0'&&c<='9') { x=(x<<3)+(x<<1)+(c^48); c=getchar();}
	return f==1?x:-x;
}
inline void print(int x){
	if(x<0) x=~x+1,putchar('-');
	if(x>=10) print(x/10);
	putchar((x%10)|48);
}
int T;
int n;
int a[110];
map<int,int>mp;
int main(){
	T=read();
	while(T--){
		mp.clear();
		int ans1=0,ans2=0;
		n=read();
		for(int i=1;i<=n;++i) a[i]=read(),mp[a[i]]++;
		for(int i=0;i<=100;++i){
			if(mp.count(i)){
				++ans1;
				if(mp[i]>=2&&ans2==i) ++ans2;
			}
			else break ;
		}
		printf("%d\n",ans1+ans2);
	}
	return 0;
}