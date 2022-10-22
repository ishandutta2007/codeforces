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
long long tot,tmp;
int R[500010];
int S[500010];
int n;
char str[500010];
int main(){
	n=read();
	scanf("%s",str+1);
	for(int i=1;i<=n;++i) S[i]=str[i]-'0';
	for(int i=1;i<=n;++i){
		if(S[i]==0) tot+=tmp;
		else{
			int l=i,r=i;
			while(r<n&&S[r+1]==1) ++r;
			for(int j=1;j<=(r-l+1);++j){
				tmp+=(l+j-1)-R[j];
				tot+=tmp;
				R[j]=(r-j+1);
			}
			i=r;
		}
	}
	printf("%lld\n",tot);
}