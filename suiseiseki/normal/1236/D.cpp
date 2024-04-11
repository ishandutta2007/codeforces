#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
template<typename T1, typename T2> void maxup(T1& h, T2 g) {
	if (h < g) h = g;
}
template<typename T1, typename T2> void minup(T1& h, T2 g) {
	if (h > g) h = g;
}
int getint() {
	int res = 0, neg = 0, ch = getchar();
	while (not(isdigit(ch) or ch == '-') and ch != EOF) ch = getchar();
	if (ch == '-') neg = 1, ch = getchar();
	while (isdigit(ch)) res = res * 10 + ch - 48, ch = getchar();
	return neg ? -res : res;
}
const int N = 2e5 + 10, E = 5e5 + 10;
const LL INF = 1e9;
vector<int> nnode[N], mnode[N];
int n, m, k;
struct P{
	int x,y;
}p[N];
bool cmpx(const P& h, const P& g) {
	return h.x<g.x;
}
bool cmpy(const P& h, const P& g) {
	return h.y<g.y;
}
int main(){
	scanf("%d%d%d",&n,&m,&k);
	int al=0,ar=m+1,au=0,ad=n+1;
	for (int i=1;i<=n;i++){
		nnode[i].push_back(0);
	}
	for(int i=1;i<=m;i++){
		mnode[i].push_back(0);
	}
	LL taken=1;
	for(int i=1;i<=k;i++){
		scanf("%d%d",&p[i].x,&p[i].y);
	}
	sort(p+1,p+1+k,cmpy);
	for(int i=1;i<=k;i++){
		nnode[p[i].x].push_back(p[i].y);
	}
	sort(p+1,p+1+k,cmpx);
	for(int i=1;i<=k;i++){
		mnode[p[i].y].push_back(p[i].x);
	}
	for(int i=1;i<=n;i++){
		nnode[i].push_back(m+1);
	}
	for(int i=1;i<=m;i++){
		mnode[i].push_back(n+1);
	}
	int x=1,y=1,d=1;
	int lx=x,ly=y;
	int l,r,mid;
	while(1){
		if(d==1||d==3){
			l=0,r=nnode[x].size()-2;
			while(l<r){
				mid=(l+r+1)/2;
				if(y>nnode[x][mid]){
					l=mid;
				}
				else{
					r=mid-1;
				}
			}
		}
		else{
			l=0,r=mnode[y].size()-2;
			while(l<r){
				mid=(l+r+1)/2;
				if(x>mnode[y][mid]){
					l=mid;
				}
				else{
					r=mid-1;
				}
			}
		}
		if(d==1){
			int ty=min(ar-1,nnode[x][l+1]-1);
			taken+=ty-y;
			au=x;
			y=ty;
			d=2;
		}
		else if(d==2){
			int tx=min(ad-1,mnode[y][l+1]-1);
			taken+=tx-x;
			ar=y;
			x=tx;
			d=3;
		}
		else if(d==3){
			int ty=max(al+1,nnode[x][l]+1);
			taken+=y-ty;
			ad=x;
			y=ty;
			d=4;
		}
		else{
			int tx=max(au+1,mnode[y][l]+1);
			taken+=x-tx;
			al=y;
			x=tx;
			d=1;
		}
		if(lx==x&&ly==y&&(!(x==1&&y==1&&d==2))){
			break;
		}
		lx=x;
		ly=y;
	}
	if(taken+k==1ll*n*m){
		puts("Yes");
	}
	else{
		puts("No");
	}
	return 0;
}