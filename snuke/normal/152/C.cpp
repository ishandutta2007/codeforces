#include<cstdio>
#include<algorithm>
#define fi first
#define se second
#define rep(i,n) for(int i = 0; i < n; i++)
#define rrep(i,n) for(int i = 1; i <= n; i++)
using namespace std;
typedef long long int ll;
typedef pair<int,int> P;
typedef pair<P,int> Q;

const int MX = 105, INF = 100000000, mod = 1000000007;

char a[MX][MX];
//bool b[MX][MX];
bool b[26];

int main(){
	int n, m, c;
	ll ans = 1;
	scanf("%d%d",&n,&m);
	
	rep(i,n) scanf("%s",a[i]);
	
	/*
	bool bl, bc;
	for(int k = 0; k < m; k++){
		c = d = 0;
		rep(i,n){
			bl = bc = true;
			rep(j,i){
				if(a[i][k] != a[j][k]) b[i][j] = true;
				if(b[i][j]) bl = false;
				if(a[i][k+1] == a[j][k+1]) bc = false;
			}
			if(!bl) c++;
			if(bc) d++;
		}
		
		printf("%d %d\n",c,d);
		ans += c*d;
		ans %= mod;
	}
	*/
	
	rep(i,m){
		rep(j,26) b[j] = false;
		rep(j,n){
			b[a[j][i]-'A'] = true;
		}
		c = 0;
		rep(j,26) if(b[j]) c++;
		ans = ans*c%mod;
	}
	
	printf("%d\n",(int)ans);
	
	return 0;
}