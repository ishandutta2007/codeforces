#include<bits/stdc++.h>

using namespace std;


int main() {
    ios_base::sync_with_stdio(0);
   vector<char> a(2000001, 'a');
   int n, k, f;
   cin >> n;
   vector<string>s(n);
   vector<pair<int, int>> pos;
   for(int i = 0; i < n; i++){
        cin >> s[i] >> k;
        for(int j = 0; j < k; j++){
            cin >> f; f--;
            pos.push_back(make_pair(f, i));
        }
   }
   sort(pos.begin(), pos.end());
   int cp = 0;
   for(int i = 0; i < pos.size(); i++){
        for(int j = max(0, cp - pos[i].first); j < s[pos[i].second].size(); j++){
            a[pos[i].first + j] = s[pos[i].second][j];
        }
        cp = max(cp, (int) (pos[i].first + s[pos[i].second].size()));
   }
   string x;
   for(int i = 0; i < cp; i++)
        x += a[i];
    cout << x;
}