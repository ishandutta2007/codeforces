#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define IFOR(i, begin, end) for(int i=(end)-1,i##_begin_=(begin);i>=i##_begin_;i--)
#define REP(i, n) FOR(i,0,n)
#define IREP(i, n) IFOR(i,0,n)
constexpr int MOD = 1000000007;
constexpr int INF = 2147483647;
int main()
{
    int T;
    cin >> T;
    REP(t, T) {
        int n;
        cin >> n;
        vector<int> a(n);
        REP(i, n) cin >> a[i];
        vector<bool> nb(n);
        REP(i, n-1) {
            if(a[i] == -1 && a[i+1] != -1) {
                nb[i+1] = true;
            }
            if(a[i] != -1 && a[i+1] == -1) {
                nb[i] = true;
            }
        }
        vector<int> ad;
        REP(i, n) {
            if(nb[i]) ad.push_back(a[i]);
        }
        if(ad.size() == 0) {
            cout << "0 0" << endl;
            continue;
        }
        sort(ad.begin(), ad.end());
        int k = (ad[0] + ad[ad.size()-1]) / 2;
        int m = max(abs(ad[0]-k), abs(ad[ad.size()-1]-k));
        REP(i, n-1) {
            if(a[i] != -1 && a[i+1] != -1) {
                if(abs(a[i]-a[i+1]) > m) m = abs(a[i]-a[i+1]);
            }
        }
        cout << m << " " << k << endl;
    }
}