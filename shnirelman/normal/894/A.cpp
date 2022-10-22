#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;

int main() {
    string s;
    cin >> s;

    int ans = 0;
    for(int i = 0; i < s.length(); i++)
        for(int j = i + 1; j < s.length(); j++)
            for(int l = j + 1; l < s.length(); l++)
                if(s[i] == 'Q' && s[j] == 'A' && s[l] == 'Q')
                    ans++;

    cout << ans;
}