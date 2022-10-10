#include <bits/stdc++.h>
using namespace std;

string s, t;
map<string, int> cnts, cntt;
map<string, string> flip = {{"00", "00"}, {"01", "10"}, {"11", "11"}, {"10", "01"}};
int q;

void solve() {
    cin >> s >> t;
    string ds = s;
    vector<int> moves;
    cnts.clear();
    cntt.clear();
    int n = s.size();
    for(int i = 0; i < n/2; i++) {
        cnts[s.substr(2*i, 2)]++;
        cntt[t.substr(2*i, 2)]++;
    }
    //cout << cnts["00"] << " " << cnts["01"] << " " << cnts["10"] << " " << cnts["11"] << endl;
    //cout << cntt["00"] << " " << cntt["01"] << " " << cntt["10"] << " " << cntt["11"] << endl;
    int balance = 0;
    if(cnts["11"] != cntt["11"] || cnts["00"] != cntt["00"]) {
        cout << "-1\n";
        return;
    }
    if(cnts["01"] != cntt["10"]) {
        for(int i = 0; i < n/2; i++) {
            string p = s.substr(2*i, 2);
            balance += (p == "10");
            balance -= (p == "01");
            if(cnts["01"] + balance == cntt["10"]) {
                moves.push_back(2*i + 2);
                reverse(s.begin(), s.begin() + 2*i + 2);
                cnts["01"] = cntt["10"] = 44;
                break;
            }
        }
    }
    int after = -1;
    balance = 0;
    if(cnts["01"] != cntt["10"]) {
        for(int i = 0; i < n/2; i++) {
            string p = t.substr(2*i, 2);
            balance += (p == "01");
            balance -= (p == "10");
            if(cntt["10"] + balance == cnts["01"]) {
                after = 2*i + 2;
                reverse(t.begin(), t.begin() + 2*i + 2);
                break;
            }
        }
    }
    for(int pos = 0; pos < n; pos += 2) {
        string pair = t.substr(n - pos - 2, 2);
        for(int st = pos; st < n; st += 2) {
            if(s.substr(st, 2) == flip[pair]) {
                if(st) {
                    moves.push_back(st);
                    reverse(s.begin(), s.begin() + st);
                }
                moves.push_back(st + 2);
                reverse(s.begin(), s.begin() + st + 2);
                break;
            }
        }
    }
    if(after != -1) {
        moves.push_back(after);
        reverse(s.begin(), s.begin() + after);
    }
    cout << moves.size() << '\n';
    for(auto x : moves)
        cout << x << " ";
    cout << '\n';
}

int main() {
    cin >> q;
    for(int i = 0; i < q; i++)
        solve();
}