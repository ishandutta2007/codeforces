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

int q,m,n;
int a[666][666],b[666][666];
inline int get1(){
	int ans=0;
	for(int i=1;i<=n;i++)
		for(int j=1;j<m;j++)
			if(fabs(a[i][j]-a[i][j+1])>=10) ans++;
	for(int i=1;i<n;i++)
		for(int j=1;j<=m;j++)
			if(fabs(a[i][j]-a[i+1][j])>=10) ans++;
	return ans;
}
inline int get2(){
	int ans=0;
	for(int i=1;i<=n;i++)
		for(int j=1;j<m;j++)
			if(fabs(b[i][j]-b[i][j+1])>=10) ans++;
	for(int i=1;i<n;i++)
		for(int j=1;j<=m;j++)
			if(fabs(b[i][j]-b[i+1][j])>=10) ans++;
	return ans;
}
int main(){
	read(q);
	while(q--){
		read(n,m);
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				read(a[i][j]);
		for(int i=1;i<=n/2;i++)
			for(int j=1;j<=m;j++)
				b[i][j]=a[i+n/2][j];
		for(int i=1;i<=n/2;i++)
			for(int j=1;j<=m;j++)
				b[i+n/2][j]=a[i][j];
		int x=get1(),y=get2();
		if(x>y) puts("YES"); else puts("NO");
	}
	return 0;
}