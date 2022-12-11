#include <string>
#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

string s;
vector <pair<char, int> > v;
long long ans, l1, l2, l3;

int main() {
    cin >> s;
    s = "!" + s + "!";
    for (int i = 0; i < s.length(); i++)
        if (s[i] == '.' || s[i] == '@')
            v.push_back(make_pair(s[i], i));
    for (int i = 1; i < v.size(); i++)
    if (v[i - 1].first == '@' && v[i].first == '.') {
        l1 = l3 = 0;
        l2 = !!(v[i].second - v[i - 1].second - 1);
        for (int j = v[i - 1].second + 1; j < v[i].second; j++)
            if ((s[j] > 'z' || s[j] < 'a') && (s[j] < '0' || s[j] > '9')) l2 = 0;
        for (int j = v[i - 1].second - 1; ; j--) {
            if (s[j] != '_' && (s[j] < 'a' || s[j] > 'z') && (s[j] < '0' || s[j] > '9')) break;
            if (s[j] >= 'a' && s[j] <= 'z') l1++;
        }
        for (int j = v[i].second + 1; ; l3++, j++) {
            if (s[j] < 'a' || s[j] > 'z') break;
        }
        //cerr << l1 << " " << l2 << " " << l3 << "\n";
        ans += l1 * l2 * l3;
    }
    cout << ans;
}