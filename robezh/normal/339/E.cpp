#include <bits/stdc++.h>
using namespace std;

const int N = 1005;

typedef pair<int, int> P;
typedef pair<P, int> Pi;

int n;
vector<P> ps;
int num[N];
vector<P> pis;
stack<P> S;
vector<P> res;

void rever(vector<P> &vec, int i, int j) {
//    for(int k = i; k <= (i + j) / 2; k++) swap(vec[k], vec[i+j-k]);
    reverse(vec.begin() + i, vec.begin() + j + 1);
    for(int k = i; k <= j; k++) swap(vec[k].first, vec[k].second);
}


void search(vector<P> vec, int d) {
    if(vec == pis) {
        while(!S.empty()) {
            int l = S.top().first, r = S.top().second;
            rever(vec, l, r);
            S.pop();
            int ls = 0, rs = 0;
            for(int i = 0; i < l; i++) ls += abs(vec[i].second - vec[i].first) + 1;
            for(int i = 0; i <= r; i++) rs += abs(vec[i].first - vec[i].second) + 1;
            if(ls + 1 < rs) res.push_back({ls + 1, rs});
        }
        cout << res.size() << endl;
        for(const auto &p : res) cout << p.first << " " << p.second << endl;
        exit(0);

    }
    if(d > 2) return ;
    for(int i = 0; i < vec.size(); i++) {
        if(vec[i].first != vec[i].second) continue;
        for(int j = i + 1; j < vec.size(); j++) {
            if(vec[j].first != vec[j].second) continue;
            S.push({i, j});
            rever(vec, i, j);

            search(vec, d + 1);

            S.pop();
            rever(vec, i, j);
        }
    }
}

int main() {
    cin >> n;
    for(int i = 0; i < n; i++) cin >> num[i];
    int r = 0;
    for(int i = 0; i < n; i = r) {
        r++;
        while(r < n && abs(num[r] - num[r-1]) <= 1) r++;
        if(i + 1 < r) {
            ps.push_back({num[i], num[i]});
            if(i+1 <= r-2) ps.push_back({num[i+1], num[r-2]});
            ps.push_back({num[r-1], num[r-1]});
        }
        else ps.push_back({num[i], num[i]});
    }


    n = ps.size();
    for(int i = 0; i < ps.size(); i++) pis.push_back(ps[i]);
    sort(pis.begin(), pis.end());
    for(int i = 0; i < n; i++) {
        if(pis[i].first > pis[i].second) swap(pis[i].first, pis[i].second);
    }
//    for(auto p : pis) cout << p.first << " " << p.second << endl;
    search(ps, 0);





}