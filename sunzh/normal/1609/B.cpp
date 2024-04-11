#include<iostream>
#include<cstdio>
#include<algorithm>
#include<set>
#include<vector>
#include<ctime>
#include<cstring>
#include<map>
#include<cmath>
#include<queue>
#define mp make_pair
#define PII pair<int,int>
#define fi first
#define se second
#define pb push_back
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c)){x=(x<<3)+(x<<1)+(c^48);c=getchar();}
	return f==-1?~x+1:x;
}
int n,q;
char str[100010];
bool check(int x){
	return str[x-1]=='a'&&str[x]=='b'&&str[x+1]=='c';
}
int main(){
	n=read(),q=read();
	scanf("%s",str+1);
	int ans=0;
	for(int i=2;i<n;++i){
		ans+=check(i);
	}
	for(int i=1;i<=q;++i){
		int x=read();char c=getchar();
		while(c<'a'||c>'c') c=getchar();
		for(int j=max(2,x-1);j<=min(n-1,x+1);++j) ans-=check(j);
		str[x]=c;
		for(int j=max(2,x-1);j<=min(n-1,x+1);++j) ans+=check(j);
		printf("%d\n",ans);
	}
}