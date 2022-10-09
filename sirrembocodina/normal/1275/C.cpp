#include <iostream>
#include <map>
#include <vector>
#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); ++i)

#define pb push_back

const int mod = 1000000007;

bool g[110][110];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); 
    int n;
    cin >> n;
    forn (i, n) {
        string s;
        cin >> s;
        int sum = 0;
        bool was0 = false;
        bool was2 = false;
        forn (j, s.size()) {
            int x = s[j] - '0';
            if (x % 2 == 0) {
                if (x == 0 && !was0) {
                    was0 = true;
                } else {
                    was2 = true;
                }
            }
            sum += x;
        }
        if (sum % 3 == 0 && was0 && was2) {
            cout << "red" << endl;
        } else {
            cout << "cyan" << endl;
        }
    }
}