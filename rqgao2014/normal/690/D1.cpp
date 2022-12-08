#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<string>
#include<set>
#include<vector>
#include<map>
#include<stack>
#include<queue>
#include<bitset>
#include<functional>
#include<sstream>
#define sqr(x) (x)*(x)
#define ll long long
#define ull unsigned long long
#define ui unsigned int
#define vi vector<int>
#define pb push_back
#define ld long double
#define mp make_pair
#define pii pair<int,int>
#define pq priority_queue
#define rf random_shuffle
#define np next_permutation
#define lb lower_bound
#define debuge puts("isok")
#define debug(x) cout<<#x<<"="<<x<<endl
#define SS second
#define FF first
using namespace std;
inline void read(int &x){
	x=0;char ch=getchar(),flag=0;
	while((ch>'9'||ch<'0')&&ch!='-') ch=getchar();
	if(ch=='-') flag=1,ch=getchar();
	while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
	if(flag) x=-x;
}
inline void read(int &x,int &y){read(x),read(y);}
inline void read(int &x,int &y,int &z){read(x),read(y),read(z);}

int r,c,ans,u[4][2]={1,0,-1,0,0,1,0,-1};
char s[1005][1005];
inline void dfs(int x,int y){
	s[x][y]='.';
	for(int i=0;i<4;i++){
		int tx=x+u[i][0],ty=y+u[i][1];
		if(s[tx][ty]=='B') dfs(tx,ty);
	}
}

int main(){
	read(r,c);
	for(int i=1;i<=r;i++)
		scanf("%s",s[i]+1);
	for(int i=1;i<=r;i++)
		for(int j=1;j<=c;j++)
			if(s[i][j]=='B') ans++,dfs(i,j);
	printf("%d\n",ans);
}