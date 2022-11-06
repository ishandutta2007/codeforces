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
    int n;
    cin >> n;
    vector<int> a(n);
    REP(i, n) cin >> a[i];

    vector<bool> prime(1000001, true);
    prime[0] = false;
    prime[1] = false;
    for(int i=2; i*i<=1000001; i++) {
        if(prime[i]) {
            for(int j=i*2; j<=1000001; j+=i ){
                prime[j] = false;
            }
        }
    }

    int sum = 0;
    REP(i, n) {
        sum += a[i];
    }

    lint ansmin = 1e13;
    REP(k, 1000001) {
        if(prime[k] && sum%k == 0) {
            vector<int> loc;
            lint medium = -1;
            lint ans = 0;
            REP(i, n) {
                if(a[i] == 1) {
                    loc.push_back(i);
                    if(loc.size() == k/2+1) medium = i;
                    if(loc.size() == k) {
                        REP(j, loc.size()) {
                            ans += abs(loc[j] - medium);
                        }
                        medium = -1;
                        loc.clear();
                    }
                }
            }

            if(ans < ansmin) ansmin = ans;
        }
    }

    if(ansmin == 1e13) {
        cout << -1 << endl;
    } else {
        cout << ansmin << endl;
    }
}