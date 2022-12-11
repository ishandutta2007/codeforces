#include<bits/stdc++.h>
using namespace std;
using LL=long long;
#define FOR(i,l,r) for(int i=(l);i<=(r);++i)
#define REP(i,n) FOR(i,0,(n)-1)
#define ssize(x) int(x.size())
template<class A,class B>auto&operator<<(ostream&o,pair<A,B>p){return o<<'('<<p.first<<", "<<p.second<<')';}
template<class T>auto operator<<(ostream&o,T x)->decltype(x.end(),o){o<<'{';int i=0;for(auto e:x)o<<(", ")+2*!i++<<e;return o<<'}';}
#ifdef DEBUG
#define debug(x...) cerr<<"["#x"]: ",[](auto...$){((cerr<<$<<"; "),...)<<'\n';}(x)
#else
#define debug(...) {}
#endif

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int r;
    cin >> r;

    vector bounds = {
        1200,
        1400,
        1600,
        1900,
        2100,
        // 2300,
        2400,
        // 2600,
        3000,
    };

    for(auto x : bounds)
        if(r < x) {
            cout << x << "\n";
            return 0;
        }       
}