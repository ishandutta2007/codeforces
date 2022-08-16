#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<int,int> PI;
typedef vector<int> VI;
typedef vector<PI> VPI;

template<class T> bool tmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool tmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

#define PB(x) push_back(x)
#define MP(x,y) make_pair(x,y)
#define F first
#define S second
#define SZ(x) (int)(x).size()
#define FOR(i,a,b) for(int _n(b),i(a);i<_n;i++) 
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(),(v).end()
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define TRAV(a,x) for (auto& a : x)

void setIO() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

int n, q;

int main() {
    setIO();
    int t; cin>>t;
    while(t--) {
        cin>>n>>q;
        map<int, int> id, lid;
        int s;
        REP(i, n) {
            cin>>s;
            if(id.count(s) == 0)
                id[s] = i;
            lid[s] = i;
        }
        int a, b;
        while(q--) {
            cin>>a>>b;
            int ia = id.count(a)>0 ? id[a] : -1;
            int ib = lid.count(b)>0 ? lid[b] : -1;
            cout<<((ia!=-1 && ib!=-1 && ia<ib)?"YES":"NO")<<"\n";
        }
    }
    
    return 0;
}