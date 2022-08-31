#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef vector<int> VI;
typedef pair<int,int> PI;

#define PB(x) push_back(x)
#define MP(x,y) make_pair(x,y)
#define F first
#define S second
#define FOR(i,a,b) for(int _n(b),i(a);i<_n;i++) 
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(),(v).end()

void setIO() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

int n;
string s;

string solve() {
    const int m = 10;
    int a[m] = {0};
    for (char c : s) {
        if (c == 'L') {
            REP(i, 10) {
                if (!a[i]) {a[i]=1; break;}
            }
        } else if (c=='R') {
            REP(i, 10) {
                if (!a[m-1-i]) {a[m-1-i]=1; break;}
            }
        } else {
            a[c-'0']=0;
        }
    }
    string r = "";
    REP(i, 10) r += a[i]?'1':'0';
    return r;
}

int main() {
    setIO();
    int t=1; // ; cin>>t;
    while(t--) {
        cin>>n>>s;
        cout<<solve()<<"\n";
    }
    
    return 0;
}