#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <ctime>
#include <map>
#define fi first
#define se second
#define PA pair<int,int>
#define VI vector<int>
#define VP vector<PA >
#define mk(x,y) make_pair(x,y)
#define N 410
#define For(i,x,y) for (i=x;i<=y;i++)
using namespace std;
int i,j,k,n,m,t,an;
VI a[N];
map<string,int> v;
inline int read() {
	string s;
	cin>>s;
	int i;
	for (i=0;i<s.size();i++) {
		int A=s[i];
		if (A>='A'&&A<='Z') s[i]=A-'A'+'a';
	}
	if (!v.count(s)) v[s]=++t;
	return v[s];
}
void dfs(int x,int y) {
	int i;
	an=max(an,y);
	for (i=0;i<a[x].size();i++) {
		int A=a[x][i];
		dfs(A,y+1);
	}
}
int main() {
	scanf("%d",&n);
	For(i,1,n) {
		int A=read();
		read();
		int B=read();
		a[A].push_back(B);
	}
	For(i,1,t) dfs(i,1);
	printf("%d\n",an);
	return 0;
}