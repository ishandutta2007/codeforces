#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
typedef long long ll;
template<class T> void check_min(T &a, const T &b){ a = (a < b) ? a : b; }
template<class T> void check_max(T &a, const T &b){ a = (a > b) ? a : b; }

const int N = 2e5 + 3;

int n, m, ans;
set<int> s[N];

int score(int x){
    if(s[x].empty()) return 1;
    return x > *s[x].rbegin();
}

void add_edge(int x, int y){
    ans -= score(x) + score(y);
    s[x].insert(y);
    s[y].insert(x);
    ans += score(x) + score(y);
}

void rem_edge(int x, int y){
    ans -= score(x) + score(y);
    s[x].erase(y);
    s[y].erase(x);
    ans += score(x) + score(y);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    ans = n;
    for(int i = 0; i < m; ++i){
        int x, y;
        cin >> x >> y;
        add_edge(x, y);
    }

    int q;
    cin >> q;

    while(q--){
        int type;
        cin >> type;
        if(type == 3){
            cout << ans << "\n";
            continue;
        }
        int x, y;
        cin >> x >> y;
        if(type == 1) add_edge(x, y);
        else rem_edge(x, y);
    }
}