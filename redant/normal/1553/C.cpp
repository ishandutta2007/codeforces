#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

#define FOR(i,a,b) for(int _n(b),i(a);i<_n;i++) 
#define REP(i,n) FOR(i,0,n)

void setIO() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

string s;

bool done(int k, int a, int b) {
    int ka = (k+1)/2, kb = k - ka;
    if (a > b) {
        if (a>b+5-kb) return true;
    } else if (a < b) {
        if (b>a+5-ka) return true;
    }
    
    return false;
}

int solve2() {
    int mn = 10;
    REP(k, 2) {
        int sc[2] = {0};
        string t;
        REP(i, 10) {
            if ((i&1) == k) {
                if (s[i] != '0') {
                    sc[i&1]++;
                    t+='1';
                } else {
                    t+='0';
                }
            }
            else {
                if (s[i] == '1') {
                    sc[i&1]++;
                    t+='1';
                }
                else {
                    t+='0';
                }
            }

            if (done(i+1,sc[0],sc[1])) {
                // cout << "t = " << t << endl;
                mn = min(mn, i+1);
                break;
            }
        }
    }
    return mn;
}

int main() {
    setIO();
    int t; cin>>t;
    while(t--) {
        cin>>s;
        // cout<<solve(0, 0, 0)<<"\n";
        cout<<solve2()<<"\n";
    }
    return 0;
}