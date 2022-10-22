#include <bits/stdc++.h>

using namespace std;

vector <int> str;

bool fl = 0;

int main() {
    string s1, s2;
    cin >> s1 >> s2;
    vector <pair <char, char> > data;
    vector <int> kek(31, -1);
    for (int i = 0; i < s1.size(); i++) {
        int a1 = s1[i] - 'a';
        int a2 = s2[i] - 'a';
        if (a1 != a2) {
            if ((kek[a2] != -1 && kek[a2] != a1) || (kek[a1] != -1 && kek[a1] != a2)) {
                cout << -1;
                return 0;
            } else if (kek[a1] == -1) {
                data.push_back({s1[i], s2[i]});
                kek[a2] = a1;
                kek[a1] = a2;
            }
        } else {
            if (kek[a1] != -1 && kek[a1] != -2) {
                cout << -1;
                return 0;
            }
            kek[a1] = -2;
        }
    }
    cout << data.size() << endl;
    for (int i = 0; i < data.size(); i++) {
        cout << data[i].first << " " << data[i].second << endl;
    }
 }