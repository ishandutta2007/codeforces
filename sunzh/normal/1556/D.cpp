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
int n,k;
int s[10010];
int ask(int op,int x,int y){
	if(op==0) printf("or ");
	else printf("and ");
	printf("%d %d\n",x,y);
	fflush(stdout);
	int val=read();
	if(val==-1) exit(0);
	return val;
}
int main(){
	n=read(),k=read();
	int a1=ask(0,1,2)+ask(1,1,2),a2=ask(0,1,3)+ask(1,1,3),a3=ask(0,2,3)+ask(1,2,3);
	s[1]=(a1+a2-a3>>1);
	s[2]=(a1+a3-a2>>1);
	s[3]=(a2+a3-a1>>1);
	for(int i=4;i<=n;++i){
		s[i]=ask(0,1,i)+ask(1,1,i)-s[1];
	}
	sort(s+1,s+n+1);
	printf("finish %d\n",s[k]);fflush(stdout);
	return 0;
}