#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
#include<set>
#define int long long
#define PII pair<int,int>
#define mp make_pair
#define pb push_back
#define fi first
#define se second
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
int n;
vector<int>vec[510];
const int mod=1e9+7;
int a[510];
int s[510];
int sum;
signed main(){
	n=read();
	s[0]=1;
	for(int i=1;i<=n;++i) s[i]=(s[i-1]<<1)%mod;
	for(int i=1;i<=n;++i){
		a[i]=read();if(a[i]>0) vec[a[i]].pb(i);
	}
	for(int i=1;i<=n;++i){
		if(a[i]==-1){
//			printf("i:%d,vec[i].size:%d\n",i,s[vec[i].size()]);
			(sum+=s[vec[i].size()]-1)%=mod;
		}
	}
	printf("%d\n",(s[n-1]-1-sum+mod)%mod);
	return 0;
}