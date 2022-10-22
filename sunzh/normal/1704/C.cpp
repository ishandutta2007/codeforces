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
#include<random>
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
int n,m;
int a[100010],b[100010];
int main(){
	T=read();
	while(T--){
		n=read(),m=read();
		for(int i=1;i<=m;++i) a[i]=read();
		sort(a+1,a+m+1);
		for(int i=2;i<=m;++i) b[i]=a[i]-a[i-1]-1;
		b[1]=a[1]-1+n-a[m];
		sort(b+1,b+m+1);
		int nwt=0,safe=0;
		for(int i=m;i>=1;--i){
			if(b[i]-nwt*2-3>=0){
				safe+=b[i]-nwt*2-1;nwt+=2;
			}
			else if(b[i]-nwt*2-1>=0){
				nwt++;safe++;
			}
		}
		printf("%d\n",n-safe);
	}
}