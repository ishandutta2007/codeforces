#include <bits/stdc++.h>
#define ll long long
#define INF 1000000005
#define MOD 1000000007
#define EPS 1e-10
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define rrep(i,n) for(int i=(int)(n)-1;i>=0;--i)
#define srep(i,s,t) for(int i=(int)(s);i<(int)(t);++i)
#define each(a,b) for(auto& (a): (b))
#define all(v) (v).begin(),(v).end()
#define len(v) (int)(v).size()
#define zip(v) sort(all(v)),v.erase(unique(all(v)),v.end())
#define cmx(x,y) x=max(x,y)
#define cmn(x,y) x=min(x,y)
#define fi first
#define se second
#define pb push_back
#define show(x) cout<<#x<<" = "<<(x)<<endl
#define spair(p) cout<<#p<<": "<<p.fi<<" "<<p.se<<endl
#define sar(a,n) cout<<#a<<":";rep(kbrni,n)cout<<" "<<a[kbrni];cout<<endl
#define svec(v) cout<<#v<<":";rep(kbrni,v.size())cout<<" "<<v[kbrni];cout<<endl
#define svecp(v) cout<<#v<<":";each(kbrni,v)cout<<" {"<<kbrni.first<<":"<<kbrni.second<<"}";cout<<endl
#define sset(s) cout<<#s<<":";each(kbrni,s)cout<<" "<<kbrni;cout<<endl
#define smap(m) cout<<#m<<":";each(kbrni,m)cout<<" {"<<kbrni.first<<":"<<kbrni.second<<"}";cout<<endl

using namespace std;

typedef pair<int,int> P;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<double> vd;
typedef vector<P> vp;
typedef vector<string> vs;

const int MAX_N = 1000005;

ll inv[MAX_N],fac[MAX_N],finv[MAX_N];

void make()
{
	fac[0] = fac[1] = 1;
	finv[0] = finv[1] = 1;
	inv[1] = 1;
	for(int i=2;i<MAX_N;i++){
		inv[i] = MOD - inv[MOD%i] * (MOD/i) % MOD;
		fac[i] = fac[i-1] * (ll) i % MOD;
		finv[i] = finv[i-1] * inv[i] % MOD;
	}
}

ll add(ll x,ll y)
{
    return (x + y)%MOD;
}

ll sub(ll x,ll y)
{
    return (x+MOD-y)%MOD;
}

ll mul(ll x,ll y)
{
    return x*y%MOD;
}


int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vi vec(n);
    rep(i,n){
        cin >> vec[i];
    }
    sort(all(vec));
    make();
    int cnt = 0;
    int kp = 0;
    ll ans = 0;
    int mx = vec[n-1];
    // svec(vec);
    rep(i,n){
        if(vec[i] == mx){
            break;
        }
        if(i == 0 || vec[i-1] < vec[i]){
            cnt += kp;
            kp = 1;
        }else{
            kp++;
        }
        // cout << cnt << "\n";
        ans = add(ans,mul(mul(fac[n],inv[n-cnt]),vec[i]));
    }
    cout << ans << "\n";
    return 0;
}