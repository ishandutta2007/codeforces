#include <bits/stdc++.h>

using namespace std;

int n;

vector<string> query(int l, int r){
    cout << "? " << l << " " << r << "\n";
    fflush(stdout);

    vector<string> v;
    int sz = (r - l + 1);
    for(int i = 0; i < sz * (sz + 1) / 2; ++i){
        string s;
        cin >> s;
        sort(s.begin(), s.end());
        v.push_back(s);
    }
    sort(v.begin(), v.end(), [](const string &s1, const string &s2){
        if(s1.size() != s2.size())
            return s1.size() < s2.size();
        return s1 < s2;
    });
    return v;
}

int main(){
    cin >> n;
    assert(n >= 1 && n <= 100);

    if(n == 1){
        string s = query(1, 1)[0];
        cout << "! " << s << "\n";
        fflush(stdout);
        return 0;
    }

    vector<string> v1 = query(1, n);
    vector<string> v2 = query(2, n);

    vector<string> v;
    int ptr = 0;
    for(int i = 0; i < v1.size(); ++i){
        if(ptr != v2.size() && v1[i] == v2[ptr])
            ptr++;
        else
            v.push_back(v1[i]);
    }

    string prev = "";
    string answer = "";
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < v[i].size(); ++j){
            if(j == prev.size() || v[i][j] != prev[j]){
                answer += v[i][j];
                break;
            }
        }
        prev = v[i];
    }

    cout << "! " << answer << "\n";
    fflush(stdout);
}