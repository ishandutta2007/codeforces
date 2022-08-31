#include<cstdio>
#include<algorithm>
#define fi first
#define se second
#define rep(i,n) for(int i = 0; i < n; i++)
#define rrep(i,n) for(int i = 1; i <= n; i++)
using namespace std;
typedef pair<int,int> P;
typedef long long int ll;

const int MX = 10000, INF = 100000000;

bool b[100001];

int main(){
	int k, l, m, n, d, i;
	
	scanf("%d%d%d%d%d",&k,&l,&m,&n,&d);
	
	for(i = 0; i <= d; i += k) b[i] = true;
	for(i = 0; i <= d; i += l) b[i] = true;
	for(i = 0; i <= d; i += m) b[i] = true;
	for(i = 0; i <= d; i += n) b[i] = true;
	
	int ans = 0;
	for(i = 1; i <= d; i++) if(b[i]) ans++;
	printf("%d\n",ans);
	
	return 0;
}