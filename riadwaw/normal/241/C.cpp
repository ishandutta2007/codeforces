#include <iostream>
#include <cstdio>
#include <set>
#include <map>
#include <unordered_set>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>
#include <algorithm>
#include <ctime>
#include <stack>
#include <list>
using namespace std;
typedef long long li;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pi;

#define mp make_pair
#define pb push_back
#define all(s) s.begin(), s.end()
#define NAME ""
void solve();

int main() {
#ifdef DEBUG
    freopen("input", "r", stdin);
    clock_t start = clock();
#else
#endif

    solve();

#ifdef DEBUG
    cout << "\n\n\n\nTime:" << ((clock() - start) / 1.0 / CLOCKS_PER_SEC);
#endif
}
int d[1000];
int s[1000];
typedef set<pair<pi, int>> setp;
setp t, b;

setp* other(setp* x){
    return (x == &t) ? &b : &t;
}

namespace std{
    template<>
    struct hash<setp::iterator>{
        size_t operator()(setp::iterator t) const {
            return t->first.first * 10000 + t->first.second * 100 + t->second;
        }
    };
}

void solve() {
    int l,r,n;
    cin >> l >> r >>n;
    
    for(int i = 0 ; i < n ; ++i){
        int v,ll,rr;
        char a;
        cin>>v>>a>>ll>>rr;
        pair<pi, int> z = mp(mp(ll, rr), v);
        if(a == 'T')
            t.insert(z);
        else
            b.insert(z);
    }
    int ans = 0;
    for(int cnt = 1; cnt <=n; ++cnt){
        unordered_set<setp::iterator> v;
        int pr = r;
        if(cnt % 2 == 1)
            pr = 100 - pr;
        int realFinish = pr - cnt * 100;
        
        int h = l - realFinish;
        setp* cur = &b;
        int sum = 0;
        bool ok = true;
        
        for(int i = 0; i < cnt; ++i){
            
            int curH = l + i * 100;
            
            double s = curH * 100000/ (double)h;
            setp::iterator it = cur->upper_bound(mp(mp(s, 10000000), 10000000));
            
            
            if(it == cur->begin()){
                ok = false;
                break;
            }
            
            --it;
            
            if(it->first.second < s){
                ok = false;
                break;
            }
            v.insert(it);
            sum += it->second;
            cur = other(cur);
        }
        if(ok && v.size() == cnt){
            ans = max(ans, sum);
        }
    }
    
    
    
    
    
    for(int cnt = 1; cnt <=n; ++cnt){
        unordered_set<setp::iterator> v;
        int pr = r;
        if(cnt % 2 == 1)
            pr = 100 - pr;
        int realFinish = pr + cnt * 100;
        
        int h = realFinish - l;
        setp* cur = &t;
        int sum = 0;
        bool ok = true;
        
        for(int i = 0; i < cnt; ++i){
            
            int curH = 100 - l + i * 100;
            
            double s = curH * 100000/ (double)h;
            setp::iterator it = cur->upper_bound(mp(mp(s, 10000000), 10000000));
            
            
            if(it == cur->begin()){
                ok = false;
                break;
            }
            
            --it;
            
            if(it->first.second < s){
                ok = false;
                break;
            }
            v.insert(it);
            sum += it->second;
            cur = other(cur);
        }
        if(ok && v.size() == cnt){
            ans = max(ans, sum);
        }
    }
    
    cout << ans;
}