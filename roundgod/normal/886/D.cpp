#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <cstdint>
#include <set>

using namespace std;

typedef vector<int>::iterator vi;

bool check(const string& s)
{
    int chars[26] = {};
    for (char ch: s) {
        chars[ch-'a']++;
        if (chars[ch-'a'] > 1)
            return false;
    }
    return true;
}

bool has_similar(const string& s1, const string& s2)
{
    int ch1[26] = {};
    int ch2[26] = {};

    for (char ch: s1) {
        ch1[ch-'a']++;
    }

    for (char ch: s2) {
        ch2[ch-'a']++;
    }
    for (int i = 0; i < 26; ++i)
        if (ch1[i] == 1 && ch1[i] == ch2[i])
            return true;
    return false;
}

string can_append(const string& s2, const string& s1)
{
    if (s2.find(s1[0]) != string::npos) {
        int ind = s2.find(s1[0]);
        int k = 0;
        for (int i = ind; i < (int)s2.size(); ++k, ++i) {
                if (s2[i] != s1[k])
                    return "";
        }
        return s2 + s1.substr(k);
    }
    return "";
}

string can_merge(const string& s1, const string& s2)
{
    if (s1.find(s2) != string::npos) {
        return s1;
    } else if (s2.find(s1) != string::npos)
        return s2;
    else {
        string ans;
        ans = can_append(s1, s2);
        if (ans != "" && check(ans))
            return ans;
        ans = can_append(s2, s1);
        if (check(ans))
            return ans;
    }

    return "";
}

int main()
{

//    while (1) {
//        string s1, s2;
//        cin >> s1 >> s2;
//        cout << can_merge(s1,s2) << endl;
//    }

    ios_base::sync_with_stdio(0);
    int n ;
    cin >> n;

    vector<string> a;




    for (int i = 0; i < n; ++i) {
        string t;
        cin >>t;
        if (!check(t)) {
            cout << "NO\n";
            return 0;
        }


        a.push_back(t);
    }

    set<string> parts;

    parts.insert(a[0]);

    for (int i = 1; i < n; ++i) {
        bool has_sim = true;

        string next = a[i];

        vector<string> where;

        for (auto s: parts) {
            if (has_similar(next, s)) {
                has_sim = false;
                string m = can_merge(next,  s);
                if (m == "") {
                    cout << "NO\n";
                    return 0;
                }

                where.push_back(s);
                next  = m;
            }
        }
        if (!where.empty()) {
            for (auto s: where)
                parts.erase(s);
            parts.insert(next);
        }


        if (has_sim)
            parts.insert(a[i]);
    }

    for (auto s: parts)
        cout << s;
    cout << endl;




    return 0;
}