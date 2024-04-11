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
  cout << (expr ? "Yes" : "No") << endl;
}
int main()
{
    lint n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    vector<int> move;
    int minnum = 0;
    vector<int> right;
    int rightsize = 0;
    REP(i, n) {
        if(s[i] == 'R') rightsize++;
    }
    bool flipped = false;
    if(rightsize >= n/2) {
        flipped = true;
        string stmp = s;
        s = "";
        IREP(i, n) {
            if(stmp[i]=='R') {
                s += 'L';
            } else {
                s += 'R';
            }
        }
    }
    REP(i, n) {
        if(s[i]=='R') right.push_back(i);
    }
    int rightth = right.size();
    while(true) {
        bool flg = false;
        REP(i, rightth) {
            if(right[i] == (n-1)-((right.size()-1)-i)) {
                rightth = i;
                break;
            }
            if(i==right.size()-1 || right[i+1]-right[i] != 1) {
                move.push_back(right[i]+1);
                right[i]++;
                flg = true;
            }
        }
        if(!flg) break;
        minnum++;
    }
    if(k < minnum || k > move.size()) {
        cout << -1 << endl;
        return 0;
    }
    vector<int> out;
    REP(i, move.size()) {
        if(!flipped) {
            out.push_back(move[i]);
        } else {
            out.push_back(n-move[i]);
        }
        
        if(k == move.size()-i || i == move.size()-1 || move[i+1]-1 <= move[i]) {
            cout << out.size() << " ";
            REP(i, out.size()) cout << out[i] << (i!=out.size()-1 ? " " : "");
            cout << "\n";
            k--;
            out.clear();
        }
    }
}