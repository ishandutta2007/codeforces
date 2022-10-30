#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <ctime>
#define fi first
#define se second
#define PA pair<int,int>
#define VI vector<int>
#define VP vector<PA >
#define mk(x,y) make_pair(x,y)
#define N 200010
#define For(i,x,y) for (i=x;i<=y;i++)
using namespace std;
int i,j,k,n,m,ma1,ma2,s;
int w[N],h[N];
int main() {
	scanf("%d",&n);
	For(i,1,n) {
		int x,y;
		scanf("%d%d",&x,&y);
		w[i]=x,h[i]=y;
		s+=x;
		if (y>ma1) ma2=ma1,ma1=y;
		else ma2=max(ma2,y);
	}
	For(i,1,n) printf("%d ",(s-w[i])*(ma1==h[i]?ma2:ma1));
	printf("\n");
	return 0;
}