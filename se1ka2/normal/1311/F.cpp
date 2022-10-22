#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
typedef pair<P, int> PP;

template <typename T>
struct BIT
{
    int n;
    vector<T> bit;
    
    BIT(){}
    
    BIT(int n) : n(n){
        bit.resize(n + 1);
    }
    
    T sum(int i){
        i++;
        T res = 0;
        while(i){
            res += bit[i];
            i -= (i & -i);
        }
        return res;
    }
    
    void add(int i, T x){
        i++;
        while(i <= n){
            bit[i] += x;
            i += (i & -i);
        }
    }
};

ll x[200005], h[200005];
P p[200005];
PP pp[200005];

int main()
{
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) scanf("%lld", &x[i]);
    for(int i = 0; i < n; i++) scanf("%lld", &h[i]);
    for(int i = 0; i < n; i++) p[i] = P(x[i], h[i]);
    sort(p, p + n);
    for(int i = 0; i < n; i++) pp[i] = PP(P(p[i].second, p[i].first), i);
    sort(pp, pp + n);
    BIT<ll> dis(n);
    BIT<ll> cnt(n);
    ll ans = 0;
    for(int i = 0; i < n; i++){
        ans += dis.sum(pp[i].second) + cnt.sum(pp[i].second) * pp[i].first.second;
        dis.add(pp[i].second, -pp[i].first.second);
        cnt.add(pp[i].second, 1);
    }
    cout << ans << endl;
}