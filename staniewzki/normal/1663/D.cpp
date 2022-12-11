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

    string s;
    int x;

    assert(cin >> s);
    assert(cin >> x);
    assert(ssize(s) == 3);

    if(s == "ABC") {
        cout << (x <= 1999 ? "YES\n" : "NO\n");
    } else if(s == "ARC") {
        cout << (x <= 2799 ? "YES\n" : "NO\n");
    } else if(s == "AGC") {
        cout << (x >= 1200 ? "YES\n" : "NO\n");
    } else assert(false);

}