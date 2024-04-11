#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> P;


const int N = (int)1e5 + 50;

struct node {
    int x, y, z, i;
};

map<int, map<int, vector<P> > > mp;
map<int, vector<P> > mp2;
vector<int> v3;
vector<P> res;

int n;

int main() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        mp[x][y].push_back({z, i});
    }
    for(auto &m : mp) {
        for(auto &v : m.second) {
            sort(v.second.begin(), v.second.end());
        }
    }
    for(auto &m : mp) {
        for(auto &m2 : m.second) {
            auto &v = m2.second;
            while(v.size() >= 2) {
                int a = v.back().second;
                v.pop_back();
                int b = v.back().second;
                v.pop_back();
                res.push_back({a, b});
            }
            if(!v.empty()) {
                mp2[m.first].push_back({m2.first, v.back().second});
            }
        }
    }
    for(auto &m : mp2) {
        auto &v = m.second;
        while(v.size() >= 2) {
            int a = v.back().second;
            v.pop_back();
            int b = v.back().second;
            v.pop_back();
            res.push_back({a, b});
        }
        if(!v.empty()) {
            v3.push_back(v.back().second);
        }
    }
    while(v3.size() >= 2) {
        int a = v3.back();
        v3.pop_back();
        int b = v3.back();
        v3.pop_back();
        res.push_back({a, b});
    }
    for(auto p : res) cout << p.first + 1 << " " << p.second + 1 << '\n';



}