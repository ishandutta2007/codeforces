#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

#define debug(x) cerr << #x << " = " << x << ", line = " << __LINE__ << endl

void setIO() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

int n;
int a[3][3];

int main() {
    setIO();
    int t; cin>>t;
    while(t--) {
        cin>>n;
        string s; cin>>s;
        int r = 0;
        memset(a, 0, sizeof a);
        for (int i = 1; i <= s.length(); i++) {
            int d = s[i-1] - '0';
            a[i%2][d%2]++;
        }
        if (n%2 == 0) {
            r = (a[0][0] > 0) ? 2 : 1;
        } else {
            r = (a[1][1] > 0) ? 1 : 2;
        }
        cout<<r<<"\n";
    }
    
    return 0;
}