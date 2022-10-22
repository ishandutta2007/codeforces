#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

int gcd(int n, int m){
    if(n % m == 0) return m;
    return gcd(m, n % m);
}

//  mod
//  -17  5  3 (-17  3 (mod. 5))
//  -17 % 5  -2 
inline long long mod(long long a, long long m) {
    return (a % m + m) % m;
}

//  Euclid 
// ap + bq = gcd(a, b)  (p, q) d = gcd(a, b) 
long long extGcd(long long a, long long b, long long &p, long long &q) {  
    if (b == 0) { p = 1; q = 0; return a; }  
    long long d = extGcd(b, a%b, q, p);  
    q -= a/b * p;  
    return d;  
}

// 
//  (r, m)  x  r (mod. m)
//  (0, -1) 
pair<long long, long long> ChineseRem(long long b1, long long m1, long long b2, long long m2) {
  long long p, q;
  long long d = extGcd(m1, m2, p, q); // p is inv of m1/d (mod. m2/d)
  if ((b2 - b1) % d != 0) return make_pair(0, -1);
  long long m = m1 * (m2/d); // lcm of (m1, m2)
  long long tmp = (b2 - b1) / d * p % (m2/d);
  long long r = mod(b1 + m1 * tmp, m);
  return make_pair(r, m);
}

int a[500005], b[500005];
int c[1000005], d[1000005];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n, m, k;
    cin >> n >> m >> k;
    k--;
    for(int i = 0; i <= 1000000; i++) c[i] = d[i] = -1;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        c[a[i]] = i;
    }
    for(int i = 0; i < m; i++){
        cin >> b[i];
        d[b[i]] = i;
    }
    ll g = gcd(n, m);
    ll s = n * m / g;   // 1 round
    vector<ll> v;
    for(int i = 0; i < m; i++){
        if(c[b[i]] != -1 && (i - c[b[i]]) % g == 0){
            v.push_back(ChineseRem(c[b[i]] / g, n / g, i / g, m / g).first * g + i % g);
            s--;
        }
    }
    sort(v.begin(), v.end());
    ll ans = n * m / g * (k / s);
    k %= s;
    ll left = -1, right = n * m / g;
    while(right - left > 1){
        ll mid = (right + left) / 2;
        if(mid - (lower_bound(v.begin(), v.end(), mid) - v.begin()) <= k) left = mid;
        else right = mid;
    }
    cout << ans + right << endl;
}