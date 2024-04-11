#include<iostream>
#include<cstdio>
#include<algorithm>
#include<set>
#include<vector>
#include<ctime>
#include<cstring>
#include<map>
#include<queue>
#define mp make_pair
#define PII pair<int,int>
#define fi first
#define se second
#define int long long
#define pb push_back
using namespace std;
inline int read(){
	int x=0,f=1;
	char c=getchar();
	while(!isdigit(c)){if(c=='-') f=-1;c=getchar();}
	while(isdigit(c)){x=(x<<3)+(x<<1)+(c^48);c=getchar();}
	return f==1?x:~x+1;
}
int T;
signed main(){
	T=read();
	while(T--){
		int n=read();
		if(n%2050==0){
			int t=n/2050;
			int ans=0;
			while(t){
				ans+=t%10;
				t/=10;
			}
			printf("%d\n",ans);
		}
		else printf("-1\n");
	}
}