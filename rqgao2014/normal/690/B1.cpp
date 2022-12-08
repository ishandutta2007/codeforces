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

int n,a[55][55],b[55][55],ax,ay,bx,by;
char s[100];

inline bool check(){
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if(a[i][j]!=b[i][j]) return 0;
	return 1;
}
int main(){
	read(n);
	for(int i=1;i<=n;i++){
		scanf("%s",s+1);
		for(int j=1;j<=n;j++)
			a[i][j]=s[j]-'0';
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if(a[i][j]==4){
				bx=i,by=j;
				if(!ax) ax=i,ay=j;
			}
	if(!ax){puts("no");return 0;}
	for(int i=ax;i<=bx;i++)
		for(int j=ay;j<=by;j++)
			b[i][j]=4;
	for(int i=ax;i<=bx;i++)
		b[i][ay-1]=2,b[i][by+1]=2;
	for(int i=ay;i<=by;i++)
		b[ax-1][i]=b[bx+1][i]=2;
	b[ax-1][ay-1]=1;
	b[ax-1][by+1]=1;
	b[bx+1][ay-1]=1;
	b[bx+1][by+1]=1;
	if(check()) puts("yes"); else puts("no");
	return 0;
}