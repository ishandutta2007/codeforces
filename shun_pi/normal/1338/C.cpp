#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define IFOR(i, begin, end) for(int i=(end)-1,i##_begin_=(begin);i>=i##_begin_;i--)
#define REP(i, n) FOR(i,0,n)
#define IREP(i, n) IFOR(i,0,n)
constexpr int MOD = 1000000007;
constexpr int INF = 2147483647;
void yes(bool expr) {
  cout << (expr ? "Yes" : "No") << "\n";
}
lint solve1(lint n, lint numl, lint numr, lint posl, lint posr) {
    if(numl == numr) return numl;
    lint range = (posr - posl) / 4;
    if(n < range) {
        return solve1(n, numl, numl+range, posl, posl+range);
    } else if(n < 2*range) {
        return solve1(n-range, numl+2*range, numl+3*range, posl+range, posl+2*range);
    } else if(n < 3*range) {
        return solve1(n-2*range, numl+3*range, numr, posl+2*range, posl+3*range);
    } else {
        return solve1(n-3*range, numl+range, numl+2*range, posl+3*range, posr);
    }
}
lint solve2(lint n, lint numl, lint numr, lint posl, lint posr) {
    if(numl+1 == numr) return numl;
    lint range = (posr - posl) / 4;
    if(n < range) {
        return solve2(n, numl, numl+range, posl, posl+range);
    } else if(n < 2*range) {
        return solve2(n-range, numl+3*range, numr, posl+range, posl+2*range);
    } else if(n < 3*range) {
        return solve2(n-2*range, numl+range, numl+2*range, posl+2*range, posl+3*range);
    } else {
        return solve2(n-3*range, numl+2*range, numl+3*range, posl+3*range, posr);
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);


    vector<bool> used(10000000);
    vector<lint> ans;
    while(ans.size() < 30) {
        FOR(i, 1, 10000000) {
            if(!used[i]) {
                FOR(j, i+1, 10000000) {
                    if(!used[j] && !used[i^j]) {
                        ans.push_back(i);
                        ans.push_back(j);
                        ans.push_back(i^j);
                        used[i] = true;
                        used[j] = true;
                        used[i^j] = true;
                        break;
                    }
                }
                break;
            }
        }
    }
    //REP(i, ans.size())  cout << ans[i] << endl;
    //return 0;

    int T;
    cin >> T;
    REP(t, T) {
        lint n;
        cin >> n;
        //n = t;
        n += 2;
        lint k = n%3;
        n /= 3;
        lint groupsize = 1;
        while(n > groupsize) {
            n -= groupsize;
            groupsize *= 4;
        }
        n--;
        lint ans = 0;
        if(k == 0) {
            ans = groupsize + n;
        } else if(k == 1) {
            ans = solve1(n, groupsize*2, groupsize*3, 0, groupsize);
        } else {
            ans = solve2(n, groupsize*3, groupsize*4, 0, groupsize);
        }
        cout << ans << "\n";
    }

    return 0;
}