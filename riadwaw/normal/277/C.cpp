#include <iostream>
#include <cstdio>
#include <set>
#include <map>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <ctime>
#include <stack>
#include <cassert>
#include <list>
#include <unordered_set>
using namespace std;
typedef long long li;
typedef long double ld;

#define mp make_pair
#define pb push_back
#define all(s) s.begin(), s.end()
void solve();

int main() {
#ifdef DEBUG
    freopen("input", "r", stdin);
    //freopen("output", "w", stdout);
    clock_t start = clock();
#else
#endif
    ios_base::sync_with_stdio(false);
    int t = 1;
    //cin >> t;
    while (t--)
        solve();

#ifdef DEBUG
    //cout << "\n\n\nTime:" << ((clock() - start) / 1.0 / CLOCKS_PER_SEC);
#endif
    return 0;

}
#define int li


typedef vector<int> vi;
typedef pair<int, int> pi;

int n, m, k;
map<int, vector<pi>> cx, cy;
map<int, int> acx, acy;

pi get(vector<pi>& v, int z){
    int last = 0;
    int cur = 0;
    for(const pi& t: v){
        if(t.first > last){
            cur += t.first - last;
        }
        
        if(cur >= z){
            return mp(0, t.first - (cur - z));
        }

        last = max(last, t.second);
    }
    
    return mp(0, last + (z - cur));
}
void solve(){
    cin >> n >> m >> k;
    for(int i = 0; i < k; ++i){
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2>>y2;
        if(x1 > x2)
            swap(x1, x2);
        if(y1>y2)
            swap(y1, y2);
        if(x1 == x2)
            cx[x1].push_back(mp(y1, y2));
        else
            cy[y1].push_back(mp(x1, x2));
    }
    
    int gr = 0;
    
    if((n - 1 - cx.size()) % 2)
        gr ^= m;
    
    if((m - 1 - cy.size()) % 2)
        gr ^= n;
    
    for(auto& p: cx){
        sort(all(p.second));
        int last = 0;
        int cur = 0;
        for(const pi& t: p.second){
            if(t.first > last){
                cur += t.first - last;
            }
            
            last = max(last, t.second);
        }
        cur += m - last;
        
        acx[p.first] = cur;
        
        gr ^= cur;
    }
    
    for(auto& p: cy){
        sort(all(p.second));
        int last = 0;
        int cur = 0;
        for(const pi& t: p.second){
            if(t.first > last){
                cur += t.first - last;
            }
            
            last = max(last, t.second);
        }
        cur += n - last;
        
        acy[p.first] = cur;
        
        gr ^= cur;
    }
    
    if(gr == 0){
        cout << "SECOND";
        return;
    }
    
    cout << "FIRST\n";
    
    
    for(auto& p: acx){
        if((p.second ^ gr) < p.second){
            pi t = get(cx[p.first], p.second - (p.second ^ gr));
            cout << p.first << ' '<<t.first << ' '<<p.first << ' '<<t.second ;
            return;
        }
    }
    
    for(auto& p: acy){
        if((p.second ^ gr) < p.second){
            pi t = get(cy[p.first], p.second - (p.second ^ gr));
            cout << t.first << ' '<<p.first << ' '<<t.second <<' '<<p.first;
            return;
        }
    }
    
    if((n - 1 != cx.size()) && ((m ^ gr) < m)){
        for(int i = 1; ;++i){
            if(cx.find(i) == cx.end()){
                cout << i << ' '<< 0 << ' '<<i << ' '<<(m - (gr^m));
                return;
            }
        }   
    }
    if((m - 1 != cy.size()) && ((n ^ gr) < n)){
        for(int i =1; ;++i){
            if(cy.find(i) == cy.end()){
                cout << 0 << ' '<< i << ' '<<(n - (gr^n))<<' ' <<i << ' ';
                return;
            }
        }
    }
    
    assert(false);
}