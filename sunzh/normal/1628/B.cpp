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
char str[400010][11];
map<int,int>Map2,Map3[2];
int turn(char a,char b){
	return (a-'a'+1)*31+(b-'a'+1);
}
int turn(char a,char b,char c){
	return (a-'a'+1)*31*31+(b-'a'+1)*31+(c-'a'+1);
}
int main(){
	T=read();
	while(T--){
		Map2.clear();Map3[0].clear();Map3[1].clear();
		n=read();
		bool f=0;
		for(int i=1;i<=n;++i){
			memset(str[i],0,sizeof(str[i]));
			scanf("%s",str[i]+1);
			if(strlen(str[i]+1)==1){
				f=1;
			}
			if(strlen(str[i]+1)==2&&str[i][1]==str[i][2]) f=1;
			if(strlen(str[i]+1)==3&&str[i][1]==str[i][3]) f=1;
		}
		if(f) printf("YES\n");else{
			for(int i=1;i<=n;++i){
				if(strlen(str[i]+1)==2){
					int t=turn(str[i][1],str[i][2]);
					if(Map2.count(t)||Map3[0].count(t)){
						f=1;break ;
					}
					Map2[turn(str[i][2],str[i][1])]=1;
				}
				else{
					int t=turn(str[i][2],str[i][3]);
					if(Map2.count(t)) f=1;
					t=turn(str[i][1],str[i][2],str[i][3]);
					if(Map3[1].count(t)) f=1;
					Map3[0][turn(str[i][2],str[i][1])]=1;
					Map3[1][turn(str[i][3],str[i][2],str[i][1])]=1;
				}
				if(f) break ;
			}
			if(f) printf("YES\n");else printf("NO\n");
		}
	}
}