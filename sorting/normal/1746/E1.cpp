#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
template<class T> void check_min(T &a, const T &b){ a = (a < b) ? a : b; }
template<class T> void check_max(T &a, const T &b){ a = (a > b) ? a : b; }
#define all(x) (x).begin(), (x).end()

int query(vector<int> v){
    if(!v.size())
        return false;

    cout << "? " << v.size() << " ";
    for(int x: v)
        cout << x << " ";
    cout << endl;

    string s;
    cin >> s;
    return s == "YES";
}

map<int, vector<int>> valid_states_map;

int main(){
    // ios::sync_with_stdio(false);
    // cin.tie(NULL);

    int n;
    cin >> n;

    vector<int> v(n);
    iota(all(v), 1);

    while(v.size() > 3){
        int cnt = 2;
        while((1 << (cnt + 1)) <= v.size())
            ++cnt;

        if(!valid_states_map.count(cnt)){
            auto valid = [&](int state){
                for(int i = 0; i < cnt - 1; ++i)
                    if(!(state >> i & 1) && !(state >> (i + 1) & 1))
                        return false;
                return true;
            };

            vector<int> valid_states;
            for(int i = 0; i < (1 << cnt); ++i){
                if(valid(i)){
                    valid_states.push_back(i);
                }
            }
            valid_states_map[cnt] = valid_states;
        }
        vector<int> &valid_states = valid_states_map[cnt];

        vector<int> q;
        for(int i = 0; i < cnt; ++i){
            vector<int> quer_v;
            for(int j = 0; j < v.size(); ++j){
                if(j >> i & 1)
                    quer_v.push_back(v[j]);
            }
            q.push_back(query(quer_v));
        }

        vector<int> new_v;
        for(auto state: valid_states){
            // cout << state << " state" << endl;
            for(int i = 0; i < cnt; ++i)
                state ^= (!q[i]) << i;
            new_v.push_back(v[state]);
            if(state + (1 << cnt) < v.size())
                new_v.push_back(v[state + (1 << cnt)]);
        }
        sort(all(new_v));
        // for(int x: new_v)
            // cout << x << " ";
        // cout << " new_v" << endl;
        swap(new_v, v);
    }

    if(v.size() == 3){
        string s[4];
        cout << "? 1 " << v[0] << endl;
        cin >> s[0];
        cout << "? 1 " << v[1] << endl;
        cin >> s[1];
        cout << "? 1 " << v[1] << endl;
        cin >> s[2];
        cout << "? 1 " << v[0] << endl;
        cin >> s[3];

        int a[4];
        for(int i = 0; i < 4; ++i)
            a[i] = s[i] == "YES";

        if(a[1] == a[2]){
            if(!a[1])
                v.erase(v.begin() + 1);
            else{
                cout << "! " << v[1] << endl;
                return 0;
            }
        }
        else if(a[0] != a[1]){
            if(!a[0]){
                v.erase(v.begin() + 0);
            }
            else{
                v.erase(v.begin() + 1);
            }
        }
        else if(a[2] != a[3]){
            if(!a[3]){
                v.erase(v.begin() + 0);
            }
            else{
                v.erase(v.begin() + 1);
            }
        }
        else{
            v.erase(v.begin() + 2);
        }
    }

    for(int x: v){
        cout << "! " << x << endl;
        string s;
        cin >> s;
        if(s == ":)")
            return 0;
    }
}