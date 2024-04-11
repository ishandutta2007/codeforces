#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<cmath>
#define ll long long
#define maxn 200020
using namespace std;
inline int getint(){
    char c=getchar();int x=0;bool p=0;
    while((c>'9'||c<'0')&&c!='-')c=getchar();
    if(c=='-')p=1,c=getchar();
    while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();
    if(p)x=-x;return x;
}
int n,a[maxn],dp[maxn][2][3];//1 (1 2 
int main(){
	memset(dp[1],0,sizeof(dp[1]));
	int t=getint();
	while(t--){
		n=getint();
		for(int i=1;i<=n;++i)a[i]=getint();
		int t1=-1,t2=-1;
		for(int i=1;i<n;++i)
		if(a[i]==a[i+1]){
			if(t1==-1)t1=i;
			t2=i+1; 
		}
		if(t1==-1){
			puts("0");
			continue;
		}
		if(t1+1>=t2)puts("0");
		else if(t1+2==t2)puts("1");
		else printf("%d\n",t2-t1-2);
	}
	return 0;
}