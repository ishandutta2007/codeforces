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
 

typedef vector<int> vi;
 

vi gr = {0, 0};

int get(int x) {
    if (x <= 100) return gr[x];
    return gr[68 + (x%34)];
}

void go() {
    int n; cin >> n;
    string s; cin >> s;
    
    int nA = std::count(s.begin(), s.end(), 'R');
    int nB = std::count(s.begin(), s.end(), 'B');
    int g = 0;
    
    for (int i = 0; i < n; i++) {
        int j = i+1; while (j < n && s[j] != s[j-1]) j++;
        
        g ^= get(j-i);
        i = j-1;
    }
    
    if (g) nB--;
    
    dbg(nA, nB);
    cout << (nA > nB ? "Alice" : "Bob") << '\n';
}

void solve()
{
    for (int i = 2; i <= 110; i++) {
        set<int> s;
        for (int j = 0; j <= i-2; j++) {
            s.insert(gr[j] ^ gr[i-j-2]);
        }
        gr.push_back(0);
        while (s.count(gr[i])) gr[i]++;
    }
    
    int t;
    for (cin >> t; t; t--) go();
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    solve();
    return 0;
}