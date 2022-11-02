#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;
typedef pair<int,int> pii;
typedef pair<pii,int> pi3;
#define NN 1000010
pi3 p[NN];
int n,N;
bool cmp(pi3 u,pi3 v){
	if(u.x.x/N==v.x.x/N) return u.x.y<v.x.y;
	return u.x.x<v.x.x;
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
#endif
	scanf("%d",&n);
	N=3000;
	for(int i=1;i<=n;i++){
		scanf("%d%d",&p[i].x.x,&p[i].x.y);
		p[i].y=i;
	}
	sort(p+1,p+n+1,cmp);
	for(int i=1;i<=n;i++) printf("%d ",p[i].y);
    return 0;
}