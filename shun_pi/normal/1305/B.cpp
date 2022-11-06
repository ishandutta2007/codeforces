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
    string s;
    cin >> s;
    int max = 0;
    int lidx = 0;
    int ridx = s.size()-1;
    vector<int> ans;
    while(lidx < ridx) {
        if(s[lidx] == '(') {
            if(s[ridx] == ')') {
                ans.push_back(lidx+1);
                ans.push_back(ridx+1);
                lidx++;
                ridx--;
            } else {
                ridx--;
            }
        } else {
            lidx++;
        }
    }
    
    
    if(ans.size() == 0) {
        cout << 0 << endl;
    } else {
        sort(ans.begin(), ans.end());
        cout << 1 << endl;
        cout << ans.size() << endl;
        REP(i, ans.size()) cout << ans[i] << (i!=ans.size()-1 ? " " : "");
        cout << endl;
    }
}