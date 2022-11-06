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
    int n, I;
    cin >> n >> I;
    vector<int> a(n);
    REP(i, n) cin >> a[i];
    I *= 8;
    int k = I / n;
    if(k >= 30) {
        cout << 0 << endl;
        return 0;
    }
    int d = (int)pow(2, k);
    sort(a.begin(), a.end());
    vector<int> b;
    int cnt = 0;
    REP(i, n) {
        if(i == 0 || a[i] == a[i-1]) {
            cnt++;
        } else {
            b.push_back(cnt);
            cnt = 1;
        }
    }
    b.push_back(cnt);
    if(b.size() <= d) {
        cout << 0 << endl;
        return 0;
    }
    int i = 0;
    int j = 0;
    int sum = 0;
    int max = 0;
    while(j < b.size()) {
        if(j - i + 1 > d) {
            sum -= b[i];
            i++;
        }
        sum += b[j];
        j++;
        if(sum > max) max = sum;
    }
    int ans = n - max;
    cout << ans << endl;
}