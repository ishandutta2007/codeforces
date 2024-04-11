#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
template<class T> void check_min(T &a, const T &b){ a = (a < b) ? a : b; }
template<class T> void check_max(T &a, const T &b){ a = (a > b) ? a : b; }
#define all(x) (x).begin(), (x).end()

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    cin >> s;

    vector<pair<char, int>> v;
    int cnt_1 = 0;
    for(int i = 0; i < s.size(); ++i){
        if(s[i] == '1'){
            ++cnt_1;
            continue;
        }
        if(v.empty() || v.back().first != s[i])
            v.push_back({s[i], 1});
        else
            ++v.back().second;
    }

    if(!v.empty() && v[0].first == '0'){
        for(int i = 0; i < v[0].second; ++i)
            cout << '0';
        v.erase(v.begin());
    }

    for(int i = 0; i < cnt_1; ++i)
        cout << '1';

    for(int i = 0; i < v.size(); ++i){
        for(int j = 0; j < v[i].second; ++j)
            cout << v[i].first;
    }
    
}