#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
template<class T> void check_min(T &a, const T &b){ a = (a < b) ? a : b; }
template<class T> void check_max(T &a, const T &b){ a = (a > b) ? a : b; }
#define all(x) (x).begin(), (x).end()

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    
    while(t--){
        string s;
        cin >> s;

        int cnt[26]{};
        for(char c: s)
            cnt[c - 'a']++;

        int n = s.size();
        int i;
        for(i = 0; i < n; ++i){
            --cnt[s[i] - 'a'];
            if(!cnt[s[i] - 'a'])
                break;
        }
        for(; i < n; ++i)
            cout << s[i];
        cout << "\n";
    }
}