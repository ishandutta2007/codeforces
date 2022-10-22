#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>
#include<queue>
#include<map>
#include<set>
#include<random>
#include<ctime>
#define ep emplace_back
#define PII pair<int,int>
#define pb push_back
#define fi first
#define se second
#define mp make_pair
using namespace std;
inline int read(){
	int x=0,f=1;
	char c=getchar();
	while(!isdigit(c)){if(c=='-') f=-1; c=getchar();}
	while(isdigit(c)){x=(x<<3)+(x<<1)+(c^48);c=getchar();}
	return f==1?x:~x+1;
}
int n;
int a[1010];
int ans[1010][1010];
int sum[1010];
int opt[1010];
int main(){
	n=read();
	for(int i=1;i<=n;++i) a[i]=read();
	auto cmp=[&](int x,int y){
		return a[x]>a[y];
	};
	for(int i=1;i<=n;++i) opt[i]=i;
	sort(opt+1,opt+n+1,cmp);
	for(int i=1;i<=n;++i){
		for(int j=0;j<a[opt[i]];++j){
			int p=(j+i)%(n+1)+1;
//			printf("i:%d,p:%d\n",i,p);
			ans[p][opt[i]]=1;++sum[p];
		}
	}
	vector<int>vec;
	for(int i=1;i<=n+1;++i){
		if(sum[i]) vec.pb(i);
	}
	printf("%d\n",vec.size());
	for(int i:vec){
		for(int j=1;j<=n;++j){
			putchar('0'+ans[i][j]);
		}
		putchar('\n');
	}
}