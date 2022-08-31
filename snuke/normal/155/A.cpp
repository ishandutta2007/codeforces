#include<cstdio>
#include<queue>
#include<algorithm>
#define fi first
#define se second
#define rep(i,n) for(int i = 0; i < n; i++)
#define rrep(i,n) for(int i = 1; i <= n; i++)
using namespace std;
typedef long long int ll;
typedef pair<int,int> P;
typedef pair<P,P> Q;
typedef pair<P,Q> R;

const int MX = 105, INF = 100000000;

int main(){
	int n, a, b, x, ans = 0;
	scanf("%d%d",&n,&a); b = a;
	n--;
	rep(i,n){
		scanf("%d",&x);
		if(x < a){ ans++; a = x;}
		if(x > b){ ans++; b = x;}
	}
	
	printf("%d\n",ans);
	
	return 0;
}