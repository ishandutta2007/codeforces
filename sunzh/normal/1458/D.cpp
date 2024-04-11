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
	return f==1?x:~x+1;
}
inline void print(int x){
	if(x<0) putchar('-'),x=~x+1;
	if(x>=10) print(x/10);
	putchar((x%10)|48);
}
int T;
char str[500010];
int cnt[1000010];
int main(){
	T=read();
	while(T--){
		scanf("%s",str+1);
		int d=0;
		int n=strlen(str+1);
		for(int i=0;i<=(n<<1);++i) cnt[i]=0;
		for(int i=1;i<=n;++i){
			if(str[i]=='0') --d,++cnt[d+n];else ++cnt[d+n],++d;
		}
		int s=n;
		for(int i=1;i<=n;++i){
			if(cnt[s]){
				if(cnt[s-1]>=2){
					--s;--cnt[s];putchar('0');
				}
				else{
					--cnt[s];++s;putchar('1');
				}
			}
			else if(cnt[s-1]){
				--s;--cnt[s];putchar('0');
			}
		}
		putchar('\n');
	} 
}