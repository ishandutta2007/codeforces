#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
template<class T> void check_min(T &a, const T &b){ a = (a < b) ? a : b; }
template<class T> void check_max(T &a, const T &b){ a = (a > b) ? a : b; }
#define all(x) (x).begin(), (x).end()

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    
    while(t--){
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;

        map<char, int> cnt_map;
        for(char c: s)
            ++cnt_map[c];

        for(int i = 0; i < k; ++i){
            int best = -1;
            for(int j = 0; j < n / k; ++j){
                if(!cnt_map[(char)('a' + j)])
                    break;
                --cnt_map[(char)'a' + j];
                best = j;
            }

            cout << (char)('a' + best + 1);
        }
        cout << "\n";
    }
}