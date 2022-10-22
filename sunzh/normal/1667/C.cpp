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
int n;
int main(){
	n=read();
	if(n==1||n==2){
		printf("1\n1 1\n");return 0;
	}
	printf("%d\n",(n*2+1)/3);
	while(n%3!=2){
		printf("%d %d\n",n,n);--n;
	}
	int p=(n+1)/3;
	for(int i=1;i<=p;++i) printf("%d %d\n",i,p-i+1);
	for(int i=1;i<=p-1;++i) printf("%d %d\n",n-i+1,n-p+1+i);
}