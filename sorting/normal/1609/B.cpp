#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
template<class T> void check_min(T &a, const T &b){ a = (a < b) ? a : b; }
template<class T> void check_max(T &a, const T &b){ a = (a > b) ? a : b; }
#define all(x) (x).begin(), (x).end()

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;

    int cnt = 0;
    for(int i = 0; i <= (int)s.size() - 3; ++i)
        if(s[i] == 'a' && s[i + 1] == 'b' && s[i + 2] == 'c')
            ++cnt;

    for(int i = 0; i < q; ++i){
        int pos;
        char c;
        cin >> pos >> c;
        --pos;

        for(int i = max(0, pos - 3); i <= min((int)s.size() - 3, pos); ++i)
            if(s[i] == 'a' && s[i + 1] == 'b' && s[i + 2] == 'c')
                --cnt;

        s[pos] = c;

        for(int i = max(0, pos - 3); i <= min((int)s.size() - 3, pos); ++i)
            if(s[i] == 'a' && s[i + 1] == 'b' && s[i + 2] == 'c')
                ++cnt;

        cout << cnt << "\n";
    }
}