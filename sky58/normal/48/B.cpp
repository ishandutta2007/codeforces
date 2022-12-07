#include<vector>
#include<cmath>
#include<map>
#include<cstdlib>
#include<iostream>
#include<sstream>
#include<string>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<set>
#include<stack>
#include<bitset>
#include<functional>
#include<cstdlib>
#include<ctime>
#include<queue>
#include<deque>
using namespace std;
#define pb push_back
typedef long long lint;
#define mp make_pair
#define fi first
#define se second
typedef pair<int,int> pint;
int ma[55][55];
int main()
{
	int i,j,k,l,m,n,out=1000000,a,b;
	scanf("%d %d",&n,&m);
	for(i=0;i<n;i++) for(j=0;j<m;j++) scanf("%d",&ma[i][j]);
	scanf("%d %d",&a,&b);
	for(i=0;i+a<=n;i++) for(j=0;j+b<=m;j++){
		int t=0;
		for(k=0;k<a;k++) for(l=0;l<b;l++) t+=ma[i+k][j+l];
		out=min(out,t);
	}
	for(i=0;i+b<=n;i++) for(j=0;j+a<=m;j++){
		int t=0;
		for(k=0;k<b;k++) for(l=0;l<a;l++) t+=ma[i+k][j+l];
		out=min(out,t);
	}
	cout<<out<<endl;
	return 0;
}