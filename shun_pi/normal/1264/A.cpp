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
    int T;
    cin >> T;
    REP(t, T) {
        int n;
        cin >> n;
        int idx = -1;
        int last = -1;
        vector<int> num;
        REP(i, n) {
            int p;
            cin >> p;
            if(p == last) {
                num[idx]++;
            } else {
                idx++;
                if(idx == num.size()) num.push_back(1);
                last = p;
            }
        }
        int g = num[0];
        int s = 0;
        int b = 0;
        int cumsum = num[0];
        FOR(i, 1, num.size()) {
            cumsum += num[i];
            if(cumsum > n/2) break;
            if(s <= g) {
                s += num[i];
            } else {
                b += num[i];
            }
        }

        if(s == 0 || b == 0 || s <= g || b <= g) {
            cout << "0 0 0" << endl;
        } else {
            cout << g << " " << s << " " << b << endl;
        }
    }
}