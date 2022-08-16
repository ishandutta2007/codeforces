#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef vector<int> VI;
typedef pair<int,int> PI;

#define PB(x) push_back(x)
#define MP(x,y) make_pair(x,y)
#define F first
#define S second
#define SET(v,x) memset(v,x,sizeof v)
#define FOR(i,a,b) for(int _n(b),i(a);i<_n;i++) 
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(),(v).end()
#define SZ(v) int((v).size())

#define debug(x) cerr << #x << " = " << x << ", line = " << __LINE__ << endl

void setIO() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

const int SZ = 33;
LL n, k;
LL a[SZ];

bool solve() {
    set<LL> ks;
    ks.insert(1);
    LL p=k;
    while (p>0 && p<(1e18)) {
        ks.insert(p);
        p*=k;
    }

    set<LL> as;
    REP(i, n) {
        if (a[i] == 0)
            continue;
        if (!as.insert(a[i]).second)
            return false;
    }
    
    for (auto it = ks.rbegin(); it != ks.rend() && as.size() > 0; it++) {
        LL mx = *prev(as.end());
        if (mx >= *it) {
            as.erase(mx);
            mx -= *it;
            if (mx > 0) {
                if(!as.insert(mx).second)
                    return false;
            }
        }

        // cout<<"\n--"<<*it<<endl;
        // for (auto it2 = as.rbegin(); it2 != as.rend(); it2++) {
        //     cout << *it2 << ", ";
        // }
        // cout<<endl;
     
    }

    return as.size() == 0;
}

int main() {
    setIO();
    int t; cin>>t;
    while(t--) {
        cin>>n>>k;
        REP(i, n) {
            cin>>a[i];
        }
        cout<<(solve()?"YES":"NO")<<"\n";
    }
    
    return 0;
}