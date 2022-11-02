#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
#define LL ll
#define int ll
const int N = 5e5+10;

int n,m,a[N],b[N],vis[N<<1],ans[N],cnt,x[N];
ll k;

/*
inline int cal(int a1,int a2,int n1,int n2){
	int aa[3]; a[1] = a1 , a[2] = a2;
	int p[3]; p[1] = n1 , p[2] = n2;
	for(int i = 0; i < 2; ++i) {
	  	x[i] = aa[i];
	  	for(int j = 0; j < i; ++j) {
	    	x[i] = r[j][i] * (x[i] - x[j]);
	    	x[i] = x[i] % p[i];
	    	if (x[i] < 0) x[i] += p[i];
	  	}
	}
}
*/
/*
int Exgcd(int a, int b, int &x, int &y) {
  if (!b) {
    x = 1;
    y = 0;
    return a;
  }
  int d = Exgcd(b, a % b, x, y);
  int t = x;
  x = y;
  y = t - (a / b) * y;
  return d;
}
*/

ll linear_congruence_equations(const vector<pair<LL, LL>>& p){
    function<LL(LL,LL,LL&,LL&)> exgcd = [&](LL a, LL b, LL& x, LL& y){
        if(not b) return x = 1, y = 0, a;
        LL d = exgcd(b, a % b, x, y), t = x;
        return x = y, y = t - a / b * y, d;
    };
    __int128 A = 1, B = 0;
    for(auto [a, b] : p){
        LL x, y, d = exgcd(A, a, x, y);
        if((b - B) % d) return -1;
        B += ((b - B) * x / d) % (a / d) * A;
        A = A / d * a;
        B = (B % A + A) % A;
    }
    return B;
}

inline ll gcd(ll x,ll y){
	return !y ? x : gcd(y,x%y);
}

inline void cal(int a1,int a2){
	ll as = linear_congruence_equations({{n, a1}, {m, a2}});
	if(as >= 0) ans[++cnt] = as;
}

signed main()
{
	scanf("%lld%lld%lld",&n,&m,&k);
	for(int i=1;i <= n;i++) scanf("%lld",&a[i]),vis[a[i]] = i;
	for(int i=1;i <= m;i++){
		scanf("%lld",&b[i]);
		if(vis[b[i]]) cal(vis[b[i]]-1,i-1);
	}
	sort(ans+1,ans+1+cnt);
//    for(int i=1;i <= cnt;i++) cout<<ans[i]<<' '; cout<<endl;
    k--;
	ll sum = k/(n*m/gcd(n,m)-cnt)*(n*m/gcd(n,m));
//    cout<<sum<<endl;
	k %= (n*m/gcd(n,m)-cnt);
    k++;
 //   cout<<k<<endl;
    ans[0] = -1;
    for(int i=1;i <= cnt;i++){
        if(ans[i]-ans[i-1]-1 >= k) { break; }
        else sum += ans[i]-ans[i-1] , k -= ans[i]-ans[i-1]-1;
//        cout<<i<<' '<<sum<<' '<<k<<endl;
    }
	sum += k;
	printf("%lld\n",sum);
	return 0;
}