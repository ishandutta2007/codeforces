#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;
typedef pair<int,int> pii;
typedef pair<pii,int> pI3;
typedef pair<pii,pii> pi3;
#define NN 200010
int ans[NN];
pi3 p[NN*2];
set<pI3> s;
set<pI3> :: iterator it;

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
#endif
	int n;
	scanf("%d",&n);
	int m=0;
	for(int i=1;i<=n;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		p[++m]=pi3(pii(x,i),pii(y,0));
	}
	int nn;
	scanf("%d",&nn);
	for(int i=1;i<=nn;i++){
		int x,y,cnt;
		scanf("%d%d%d",&x,&y,&cnt);
		p[++m]=pi3(pii(x,-i),pii(y,cnt));
	}
	sort(p+1,p+m+1);
	for(int i=1;i<=m;i++){
		if(p[i].x.y<0){
			s.insert(pI3(p[i].y,-p[i].x.y));
		}
		else{
			it=s.lower_bound(pI3(pii(p[i].y.x,0),0));
			if(it==s.end()){
				puts("NO");
				return 0;
			}
			pI3 x=*it;
			s.erase(it);
			x.x.y--;
			if(x.x.y) s.insert(x);
			ans[p[i].x.y]=x.y;
		}
	}
	puts("YES");

	for(int i=1;i<=n;i++) printf("%d ",ans[i]);
	return 0;
}