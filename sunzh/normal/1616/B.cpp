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
char str[100010];
int main(){
	T=read();
	while(T--){
		n=read();
		scanf("%s",str+1);
		if(str[1]==str[2]){
			printf("%c%c\n",str[1],str[2]);continue ;
		}
		int ed=n;
		bool fl=0;
		for(int i=1;i<n;++i){
			if(str[i]>str[i+1]) fl=1;
			if(str[i]<str[i+1]){
				ed=i;break ;
			}
		}
		if(!fl){
			printf("%c%c\n",str[1],str[1]);
		}
		else{
			for(int i=1;i<=ed;++i) printf("%c",str[i]);
			for(int i=ed;i>=1;--i) printf("%c",str[i]);printf("\n");
		}
	}
}