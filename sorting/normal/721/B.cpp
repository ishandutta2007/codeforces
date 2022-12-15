#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
template<class T> void check_min(T &a, const T &b){ a = (a < b) ? a : b; }
template<class T> void check_max(T &a, const T &b){ a = (a > b) ? a : b; }
#define all(x) (x).begin(), (x).end()

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;

    vector<string> p(n);
    for(int i = 0; i < n; ++i)
        cin >> p[i];

    string s;
    cin >> s;

    map<int, int> cnt;
    for(int i = 0; i < n; ++i)
        cnt[p[i].size()]++;

    int len;
    for(int i = 0; i < n; ++i){
        if(p[i] == s){
            len = p[i].size();
        }
    }

    int best = 0, worst = 0, curr = 0;
    for(auto [key, val]: cnt){
        if(key == len){
            best = curr + 1;
            worst = curr + val;
        }
        else curr += val;
    }

    auto f = [&](int x){
        return (x - 1) / k * 5 + x;
    };

    cout << f(best) << " " << f(worst) << "\n";
}