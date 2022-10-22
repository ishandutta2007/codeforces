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
int T;
int n;
int a[100010];
char str[2][100010];
int main(){
	T=read();
	while(T--){
		n=read();
		scanf("%s%s",str[0]+1,str[1]+1);
		for(int i=1;i<=n;++i){
			if(str[0][i]!=str[1][i]) a[i]=2;
			else if(str[0][i]=='0') a[i]=1;else a[i]=0;
		}
		a[n+1]=-1;
		int ans=0;
		for(int i=1;i<=n;++i){
			// printf("i::%d,a:%d\n",i,a[i]);
			if(a[i]==2) ans+=2;
			else if(a[i]==1){
				if(a[i+1]==0){
					ans+=2;++i;
				}
				else ans++;
			}
			else{
				if(a[i+1]==1){
					ans+=2;++i;
				}
			}
		}
		printf("%d\n",ans);
	}
}