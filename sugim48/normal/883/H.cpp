#include <iostream>
#include <map>
#include <algorithm>
#include <vector>

using namespace std;
template<class T> using V = vector<T>;


int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    map<char, int> mp;
    for (char c: s) {
        mp[c]++;
    }

    V<string> even;
    V<string> odd;
    string buf = "";
    for (auto p: mp) {
        if (p.second % 2) {
            string s = "";
            s += p.first;
            odd.push_back(s);
            p.second--;
        }
        for (int i = 0; i < p.second/2; i++) {
            string s;
            s += p.first;
            even.push_back(s);
        }
    }

    int X = int(even.size());
    int Y = int(odd.size());

    V<string> ans;
    if (Y == 0) {
        string s;
        for (int i = 0; i < X; i++) {
            s += even[i];
        }
        string rs = s;
        reverse(begin(rs), end(rs));
        s += rs;
        ans.push_back(s);        
    } else {
        while (true) {
            if (X % Y == 0) {
                for (int i = 0; i < Y; i++) {
                    string s;
                    for (int j = i; j < X; j += Y) {
                        s += even[j];
                    }
                    string rs = s;
                    reverse(begin(rs), end(rs));
                    s += odd[i];
                    s += rs;
                    ans.push_back(s);
                }
                break;
            }
            string s = even.back();
            even.pop_back();
            odd.push_back(s);
            odd.push_back(s);
            X--;
            Y += 2;
        }
    }
    cout << ans.size() << endl;
    for (auto s: ans) {
        cout << s << " ";
    }
    cout << endl;
    return 0;
}