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
int n,k;
int main(){
	n=read(),k=read();
	printf("? 1\n");fflush(stdout);
	int x=read();
	int pos=1;
	for(int i=1;i<=n;++i){
		pos=(pos+i-1)%n+1;
		printf("? %d\n",pos);fflush(stdout);
		x=read();
		if(x>k){
			while(1){
				pos=(pos+n-2)%n+1;
				printf("? %d\n",pos);fflush(stdout);
				x=read();
				if(x==k){
					printf("! %d\n",pos);return 0;
				}
			}
		}
		else if(x<k){
			while(1){
				pos=pos%n+1;
				printf("? %d\n",pos);fflush(stdout);
				x=read();
				if(x==k){
					printf("! %d\n",pos);return 0;
				}
			}
		}
	}
}