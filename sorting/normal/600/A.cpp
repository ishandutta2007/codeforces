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

    vector<string> v1, v2;
    auto start = s.begin();
    while(start != s.end() + 1){
        // auto it1 = find(start, s.end(), '.');
        auto it2 = find(start, s.end(), ',');
        auto it3 = find(start, s.end(), ';');

        auto mn_it = min(it2, it3);

        string curr = "";
        for(auto it = start; it != mn_it; ++it)
            curr += *it;
        start = mn_it + 1;

        bool is_num = true;
        if(curr.empty()) is_num = false;
        else if(curr[0] == '0' && curr.size() != 1) is_num = false;
        for(char c: curr)
            if(!isdigit(c)){
                is_num = false;
                break;
            }

        if(is_num) v1.push_back(curr);
        else v2.push_back(curr);

        if(mn_it == s.end())
            break;
    }

    auto print = [&](const vector<string> &v){
        if(v.empty()){
            cout << "-\n";
            return;
        }

        cout << "\"";
        for(int i = 0; i < (int)v.size() - 1; ++i)
            cout << v[i] << ",";
        cout << v.back() << "\"\n";
    };

    print(v1);
    print(v2);
}