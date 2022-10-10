#include <bits/stdc++.h>
using namespace std;

int main () {
    string s;
    int k;
    cin >> s >> k;
    vector<int> w(26);
    for (int i=0; i<26; i++)
        cin >> w[i];
    
    int mx = *max_element(w.begin(), w.end());
    int ret = 0;
    for (int i=0; i<s.size(); i++)
        ret += w[s[i]-'a'] * (i + 1);
    for (int i=s.size()+1; i<=s.size()+k; i++)
        ret += i * mx;
        cout << ret << "\n";
}