#include <bits/stdc++.h>
using namespace std;


bool solve(){
    string S, T;
    cin >> S >> T;
    vector<int> cnt(26);
    for(char& t : T) cnt[t -= 'A']++;
    reverse(S.begin(), S.end());
    string U;
    for(char& s : S) if(cnt[s -= 'A']){
        cnt[s]--;
        U.push_back(s);
    }
    reverse(U.begin(), U.end());
    return U == T;
}
int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while(T--) cout << (solve() ? "YES" : "NO") << '\n';
}