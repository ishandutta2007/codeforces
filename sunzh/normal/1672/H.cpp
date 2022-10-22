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
int n,q;
char str[200010];
int ps[200010][2];
int main(){
	n=read(),q=read();
	scanf("%s",str+1);
	for(int i=2;i<=n;++i) {
		ps[i][0]=ps[i-1][0],ps[i][1]=ps[i-1][1];
		if(str[i]==str[i-1]){
			ps[i][str[i]-'0']++;
		}
	}
	for(int i=1;i<=q;++i){
		int l=read(),r=read();
		printf("%d\n",1+max(ps[r][0]-ps[l][0],ps[r][1]-ps[l][1]));
	}
}