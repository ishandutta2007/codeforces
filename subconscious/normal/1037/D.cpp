#include<bits/stdc++.h>
#define rep(i,n) for(int i=1;i<=n;++i)
#define pb push_back
#define mp make_pair
#define x0 fuckyzc
#define y0 fuckcjb
#define x1 fuckjtjl
#define y1 fucksf
using namespace std;
typedef long long ll;
typedef long double ld;
const int N=2e5+5,P=1e9+7,inf=0x3f3f3f3f;
const ld eps=1e-9;
set<int>g[N];
bool in[N];
int a[N],n,top;
int main(){
	scanf("%d",&n);
	rep(i,n-1){
		int x,y;scanf("%d%d",&x,&y);
		g[x].insert(y);g[y].insert(x);
	}
	rep(i,n)scanf("%d",a+i);
	if(a[1]!=1){puts("No");return 0;}
	in[1]=1;top=1;
	rep(i,n){
		int x=a[i];
		while(g[x].size()){
			int y=a[top+1];
			if(top==n)break;
			if(!in[y]&&g[x].find(y)!=g[x].end()){
				in[y]=1;g[x].erase(y);++top;
			}else break;
		}
		for(auto y:g[x])if(!in[y]){puts("No");return 0;}
	}
	puts("Yes");
	return 0;
}