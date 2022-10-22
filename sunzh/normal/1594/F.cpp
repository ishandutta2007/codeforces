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
#define int long long
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c)){x=(x<<3)+(x<<1)+(c^48);c=getchar();}
	return f==-1?~x+1:x;
}
int T;
int s,n,k;
signed main(){
	T=read();
	while(T--){
		s=read(),n=read(),k=read();
		if(k>s){
			printf("NO\n");continue ;
		}
		if(k==s){
			printf("YES\n");continue ;
		}
		int cnt=(s/(k<<1))*(k<<1);
		if(s%(k<<1)>=k) cnt+=(k<<1);
		else cnt+=((s%(k<<1)+1)<<1);
		printf(cnt>2*n+1?"NO\n":"YES\n");
	}
}