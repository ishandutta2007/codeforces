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
int n;
int a[1010];
int dep[1010];
int lst[1010][1010];
int main(){
	T=read();
	while(T--){
		n=read();
		for(int i=1;i<=n;++i){
			a[i]=read();
		} 
		for(int i=1;i<=n;++i){
			if(a[i]==1){
				dep[i]=dep[i-1]+1;
				for(int j=1;j<=dep[i-1];++j) lst[i][j]=lst[i-1][j];
				lst[i][dep[i]]=1;
			}
			else{
				int t=a[i]-1;
				int pos=-1;
				for(int j=dep[i-1];j>=1;--j){
					if(lst[i-1][j]==t){
						pos=j;break ;
					}
				}
				dep[i]=pos;
				for(int j=1;j<=pos;++j) lst[i][j]=lst[i-1][j];
				lst[i][pos]++;
			}
			for(int j=1;j<dep[i];++j) printf("%d.",lst[i][j]);
			printf("%d\n",lst[i][dep[i]]);
		}
	}
}