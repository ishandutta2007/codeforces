#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int n, k;
    string s;
    cin >> n >> k >> s;
    
    unordered_map<char, int> mp;
    for (int i=n-1; i>=0; i--)
        if (mp.find(s[i]) == mp.end())
            mp.insert(make_pair(s[i], i));
    
    unordered_map<char, int> count;
    for (int i=0; i<n; i++) {
        if (count.find(s[i]) == count.end())
            count.insert(make_pair(s[i], 1));
        if (count.size() > k) {
            cout << "YES" << endl;
            return 0;
        }
        if (mp[s[i]] == i)
            count.erase(s[i]);
    }
    cout << "NO" << endl;
    
    return 0;
}