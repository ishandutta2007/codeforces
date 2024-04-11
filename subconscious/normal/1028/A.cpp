#include<bits/stdc++.h>
#define rep(i,n) for(int i=1;i<=n;++i)
using namespace std;
const int N=1e3+5,P=1e9+7;
typedef long double ld;
typedef long long ll;
int n,m,lx,rx,ly,ry;
char s[N][N];
int main(){
	scanf("%d%d",&n,&m);
	rep(i,n)scanf("%s",s[i]+1);
	rx=0,lx=0x3f3f3f3f,ry=0,ly=0x3f3f3f3f;
	rep(i,n)rep(j,m)if(s[i][j]=='B'){
		rx=max(rx,i);lx=min(lx,i);
		ry=max(ry,j);ly=min(ly,j);
	}
	printf("%d %d\n",(lx+rx)/2,(ly+ry)/2);
	return 0;
}