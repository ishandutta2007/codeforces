#include <bits/stdc++.h>

using namespace std;

set<vector<int>> s;
int n;
vector<int> v1, v2, v3;

vector<int> do_1(vector<int> p){
    for(int i = 0; i < 2 * n; i += 2)
        swap(p[i], p[i + 1]);
    return p;
}

vector<int> do_2(vector<int> p){
    for(int i = 0; i < n; ++i)
        swap(p[i], p[i + n]);
    return p;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    vector<int> p(2 * n);
    for(int i = 0; i < 2 * n; ++i)
        cin >> p[i];

    for(int i = 0; i < 2 * n; ++i)
        v1.push_back(i + 1);
    v2 = do_1(v1);
    v3 = do_2(v1);

    vector<int> start = p;
    
    int ans = 0, best = INT_MAX;
    bool b = false;
    while(true){
        if(s.count(p)) break;
        s.insert(p);
        if(p == v1){
            best = min(best, ans);
            break;
        }
        if(p == v2 || p == v3){
            best = min(best, ans + 1);
            break;
        }

        if(!b) p = do_1(p);
        else p = do_2(p);
        b = !b;
        ++ans;
    }

    ans = 0;
    b = true;
    s.clear();
    p = start;
    while(true){
        if(s.count(p)) break;
        s.insert(p);
        if(p == v1){
            best = min(best, ans);
            break;
        }
        if(p == v2 || p == v3){
            best = min(best, ans + 1);
            break;
        }

        if(!b) p = do_1(p);
        else p = do_2(p);
        b = !b;
        ++ans;
    }
    
    if(best == INT_MAX) cout << "-1\n";
    else cout << best << "\n";
}