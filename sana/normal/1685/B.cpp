#include <vector> 
#include <list> 
#include <map> 
#include <set> 
#include <queue>
#include <stack> 
#include <bitset> 
#include <algorithm> 
#include <numeric> 
#include <utility> 
#include <sstream> 
#include <iostream> 
#include <iomanip> 
#include <cstdio> 
#include <cmath> 
#include <cstdlib> 
#include <ctime> 
#include <cstring>
#include <random>
#include <chrono>
#include <cassert>

using namespace std;

#ifdef LOCAL
#define _GLIBCXX_DEBUG 1
#define dbg(...) cerr << "LINE(" << __LINE__ << ") -> [" << #__VA_ARGS__ << "]: [", DBG(__VA_ARGS__)
#else
#define dbg(...) 0
#endif
 

#define sz(x) (int)(x).size()
#define all(x) begin(x), end(x)


typedef string str;


typedef vector<int> vi;
 

#define ts to_string


str ts(const char* s) { return (str)s; }


template<class A> void pr(A x) { cout << ts(x); }

void ps() { pr("\n"); }
template<class H, class... T> void ps(const H& h, const T&... t) { pr(h); if (sizeof...(t)) pr(" "); ps(t...); }
 

bool check(int tot_fab, int tot_fba, int gen, int fa, int fb, int a, int b, int ab, int ba) {
    int use_fab = min(tot_fab, ab);
    ab -= use_fab;
    tot_fab -= use_fab;
    
    int use_fba = min(tot_fba, ba);
    ba -= use_fba;
    tot_fba -= use_fba;
    
    int gen_to_ab = min(gen, ab);
    ab -= gen_to_ab;
    gen -= gen_to_ab;
    
    int gen_to_ba = min(gen, ba);
    ba -= gen_to_ba;
    gen -= gen_to_ba;
    
    int tot_ab = tot_fab + tot_fba + gen;
    fa += tot_ab;
    fb += tot_ab;
    
    a -= fa;
    b -= fb;
    return ab == 0 && ba == 0 && a == 0 && b == 0;
}

void go() {
    int a, b, ab, ba;
    cin >> a >> b >> ab >> ba;
    
    string s;
    cin >> s;
    
    vi fab, fba;
    int fa = 0, fb = 0;
    int gen = 0;
    int conv = 0;
    
    int st = 0;
    while (st < sz(s)) {
        int ed = st;
        while (ed+1 < sz(s) && s[ed+1]!=s[ed]) ed++;
        
        int tam = ed-st+1;
        if (tam % 2 == 1) {
            gen += tam/2;
            if (s[st]=='A') fa++;
            else fb++;
        }
        else {
            if (s[st]=='A') fab.push_back(tam/2);
            else fba.push_back(tam/2);
        }
        
        st = ed+1;
    }
    
    sort(all(fab)); sort(all(fba));
    
    int tot_fab = 0, tot_fba = 0;
    for (int x : fab) tot_fab += x;
    for (int x : fba) tot_fba += x;
    
    while (true) {
        if (check(tot_fab, tot_fba, gen, fa, fb, a, b, ab, ba)) {
            ps("YES");
            return;
        }
        
        if (ab > tot_fab) {
            if (fba.empty()) {
                ps("NO");
                return;
            }
            
            gen += fba.back()-1;
            tot_fba -= fba.back();
            fba.pop_back();
        }
        else {
            if (fab.empty()) {
                ps("NO");
                return;
            }
            
            gen += fab.back()-1;
            tot_fab -= fab.back();
            fab.pop_back();
        }
        
        fa++;
        fb++;
    }
}

void solve()
{
    int t;
    for (cin >> t; t; t--) go();
    
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    solve();
    return 0;
}