#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

#define FOR(i,a,b) for(int _n(b),i(a);i<_n;i++) 
#define REP(i,n) FOR(i,0,n)

void setIO() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

int n, m;
string s, t;

int solver() {
    n = s.length();
    m = t.length();
    reverse(s.begin(), s.end());
    reverse(t.begin(), t.end());
    int pre = -1;
    int i = 0, j = 0;
    while (i < n && j < m) {
        if (s[i] == t[j]) {
            int k = i-pre-1;
            if (k%2==0) {
                ++j;
                pre=i;
            }
        }
        i++;
    }
    return j>=m;
}

// int solve() {
//     n = s.length();
//     m = t.length();
//     int pre = -1;
//     int i = 0, j = 0;
//     while (i < n && j < m) {
//         if (s[i] == t[j]) {
//             ++j;
//         } else {
//             if (pre != -1) ++i;
//             pre = i;
//         }
//         i++;
//     }
//     return (j>=m) && (n-i)%2 == 0;
// }

int main() {
    setIO();
    int tt; cin>>tt;
    while(tt--) {
        cin>>s>>t;
        // cout<<((solve()||solver())?"YES":"NO")<<"\n";
        cout<<((solver())?"YES":"NO")<<"\n";
    }
    
    return 0;
}