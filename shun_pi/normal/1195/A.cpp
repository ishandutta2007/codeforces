#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define IFOR(i, begin, end) for(int i=(end)-1,i##_begin_=(begin);i>=i##_begin_;i--)
#define REP(i, n) FOR(i,0,n)
#define IREP(i, n) IFOR(i,0,n)
constexpr int MOD = 1000000007;
int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    REP(i, n) cin >> a[i];
    vector<int> c(k);
    REP(i, n) {
        c[a[i]-1]++;
    }
    
    int ans = n%2==0 ? 0 : -1;
    REP(i, k) {
        if(c[i]%2!=0) {
            ans++;
        }
    }
    ans /= 2;
    cout << n-ans;
}