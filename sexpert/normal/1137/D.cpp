#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<string> vs;

vs query(vector<int> v) {
    cout << "next ";
    for(auto x : v)
        cout << x << " ";
    cout << '\n';
    cout.flush();
    string res;
    cin >> res;
    if(res == "stop")
        exit(0);
    int sz = stoi(res);
    vs ans(sz);
    for(auto &x : ans)
        cin >> x;
    return ans;
}



int main() {
    int fir = 0;
    while(true) {
        fir++;
        query({0});
        vs r = query({0, 1});
        bool eq = false;
        for(auto s : r) {
            bool ze = false, on = false;
            for(auto c : s) {
                if(c == '0')
                    ze = true;
                if(c == '1')
                    on = true;
            }
            if(ze && on) {
                eq = true;
                break;
            }
        }
        if(eq)
            break;
    }
    int c = 0;
    while(true) {
        c++;
        vs r = query({0});
        bool eq = false;
        for(auto s : r) {
            bool ze = false, on = false;
            for(auto ch : s) {
                if(ch == '0')
                    ze = true;
                if(ch == '1')
                    on = true;
            }
            if(ze && on) {
                eq = true;
                break;
            }
        }
        if(eq)
            break;
    }
    int adv = fir - c;
    while(adv > 0) {
        query({2, 3, 4, 5, 6, 7, 8, 9});
        adv--;
    }
    while(true) {
        vs r = query({0, 1, 2, 3, 4, 5, 6, 7, 8, 9});
        if(r.size() == 1)
            break;
    }
    cout << "done\n";
    cout.flush();
}