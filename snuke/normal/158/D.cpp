#include<cstdio>
#include<algorithm>
#define fi first
#define se second
#define rep(i,n) for(int i = 0; i < n; i++)
#define rrep(i,n) for(int i = 1; i <= n; i++)
using namespace std;
typedef long long int ll;
typedef pair<int,int> P;

const int MX = 20005, INF = 1000000000;

bool pb[MX];
int p[MX], pi;
int t[MX];
int x[500], xi;

int main(){
	int n, a, b, m, ans = 0;
	scanf("%d",&n);
	
	for(int i = 2; i < 150; i++){
		if(pb[i]) continue;
		p[pi++] = i;
		for(int j = i*i; j < 150; j+=i) pb[j] = true;
	}
	
	x[0] = 1; xi = 1; m = n;
	rep(i,pi){
		for(a = 0; !(m%p[i]); a++) m /= p[i];
		if(!a) continue;
		
		for(int j = xi-1; j >= 0; j--){
			b = x[j];
			rep(k,a) b = x[xi++] = b*p[i];
		}
	}
	
	rep(i,n){
		scanf("%d",&t[i]);
		ans += t[i];
	}
	
	xi--;
	rrep(i,xi){
		if(n/x[i] < 3) continue;
		rep(j,x[i]){
			a = 0;
			for(int k = j; k < n; k += x[i]) a += t[k];
			ans = max(ans,a);
		}
	}
	
	printf("%d\n",ans);
	
	return 0;
}