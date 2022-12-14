#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef complex<double> P;
typedef pair<int,int> pii;
#define REP(i,n) for(ll i=0;i<n;++i)
#define REPR(i,n) for(ll i=1;i<n;++i)
#define FOR(i,a,b) for(ll i=a;i<b;++i)

#define DEBUG(x) cout<<#x<<": "<<x<<endl
#define DEBUG_VEC(v) cout<<#v<<":";REP(i,v.size())cout<<" "<<v[i];cout<<endl
#define ALL(a) (a).begin(),(a).end()

#define MOD (ll)(1e9+7)
#define ADD(a,b) a=((a)+(b))%MOD
#define FIX(a) ((a)%MOD+MOD)%MOD

// Force = c_f * count(a_i==A) + c_m * min(a_i)

// N<=1e5
// a_i<=A<=1e9
// c_f,c_m<=1e3
// m<=1e15

// 2 options
// - make max score maximum     max : N times
// - make min scores +1         max : A times
// -> find ALL N & make A

ll n,A;
ll cf,cm;

#define N_MAX 100010

ll a[N_MAX];
pair<ll,ll> b[N_MAX];
ll c[N_MAX];
ll d[N_MAX];
ll e[N_MAX];
ll f[N_MAX];

int main(){
  ll m;
  cin >> n >> A >> cf >> cm >> m;
  REP(i,n) scanf("%d",&(a[i]));
  // check all maximize
  ll rest = 0;
  REP(i,n) rest += A-a[i];
  if(rest <= m){
    ll force = (ll)cf*(ll)n + (ll)cm*(ll)A;
    cout << force << endl;
    cout << A;
    REPR(i,n) cout << " " << A;
    cout << endl;
    return 0;
  }
  // (`)
  // &
  ll mp[n];
  REP(i,n) b[i] = make_pair<ll,ll>(a[i],i);
  sort(b,b+n);
  REP(i,n){
    c[i] = b[i].first;
    mp[i] = b[i].second;
  }
  // 
  d[0] = c[0];
  REPR(i,n) d[i] = c[i]+d[i-1];

  f[0] = 0;
  REPR(i,n) f[i] = (i+1)*c[i] - d[i];

  e[n-1] = c[n-1];
  REPR(i,n) e[n-1-i] = c[n-1-i]+e[n-i];
  // 
  ll mxval = 0;
  ll mxn = -1;
  REP(i,n){
    ll power = m;
    // 1st
    ll upper = 0;
    if(i!=0) upper = e[n-i];
    upper = i*A - upper;
    power -= upper;
    if(power < 0) continue;
    // 2nd
    ll iter = upper_bound(f,f+n,power)-f;
    assert(iter > 0);
    --iter;
    iter = min(iter,n-1-i);
    ll cnt = iter+1;
    power -= f[iter];
    ll downer = c[iter] + (ll)(power/cnt);
    // calc
    ll force = i*cf + downer*cm;
    if(force >= mxval){
      mxval = force;
      mxn = i;
    }
  }

  // 
  ll power = m;
  // 1st
  ll upper = 0;
  if(mxn!=0) upper = e[n-mxn];
  upper = mxn*A - upper;
  power -= upper;
  // 2nd
  ll iter = upper_bound(f,f+n,power)-f;
  assert(iter > 0);
  --iter;
  iter = min(iter,n-1-mxn);
  ll cnt = iter+1;
  power -= f[iter];
  ll downer = c[iter] + (ll)(power/cnt);
  
  // calc
  ll force = mxn*cf + downer*cm;
  REP(i,cnt) a[mp[i]] = downer;
  REP(i,mxn) a[mp[n-1-i]] = A;

  cout << force << endl;
  cout << a[0];
  REPR(i,n) cout << " " << a[i];
  cout << endl;

  return 0;
}