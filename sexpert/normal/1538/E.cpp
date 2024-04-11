#include <bits/stdc++.h>
using namespace std;
using ll = long long;

typedef pair<array<ll, 2>, array<string, 2>> gay;

gay merge(gay A, gay B) {
    ll cnt = A.first[0] + B.first[0];
    ll size = A.first[1] + B.first[1];
    string anime = A.second[1] + B.second[0];
    for(int i = 0; i + 3 < anime.size() && i < A.second[1].size(); i++)
        if(anime.substr(i, 4) == "haha")
            cnt++;
    array<ll, 2> fi = {cnt, size};
    array<string, 2> se;
    se[0] = (A.second[0] + B.second[0]).substr(0, 3);
    string lol = A.second[1] + B.second[1];
    se[1] = lol.substr(max(0, (int)lol.size() - 3), 3);
    return make_pair(fi, se);
}

ostream& operator<< (ostream& out, gay G) {
    out << "count: " << G.first[0] << " size: " << G.first[1] << " " << G.second[0] << " " << G.second[1];
    return out;
}

void solve() {
    map<string, gay> wtf;
    string pv;
    int n;
    cin >> n;
    cin.ignore();
    while(n--) {
        string s;
        getline(cin, s);
        stringstream ss(s);
        string name, op;
        ss >> name;
        ss >> op;
        pv = name;
        if(op == ":=") {
            string res;
            ss >> res;
            ll cnt = 0, size = res.size();
            for(int i = 0; i + 3 < res.size(); i++)
                if(res.substr(i, 4) == "haha")
                    cnt++;
            array<ll, 2> fi = {cnt, size};
            array<string, 2> se;
            se[0] = res.substr(0, 3);
            se[1] = res.substr(max(0, (int)res.size() - 3), 3);
            wtf[name] = make_pair(fi, se);
            //cout << wtf[name] << '\n';
        }
        else {
            string op1, op2;
            ss >> op1;
            ss >> op2;
            ss >> op2;
            wtf[name] = merge(wtf[op1], wtf[op2]);
            //cout << wtf[name] << '\n';
        }
    }
    cout << wtf[pv].first[0] << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--)
        solve();
}