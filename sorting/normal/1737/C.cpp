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
        int n;
        cin >> n;
        pair<int, int> p[3];
        for(int i = 0; i < 3; ++i)
            cin >> p[i].first >> p[i].second;
        int x, y;
        cin >> x >> y;

        sort(p, p + 3);
        if(p[0] == pair{1, 1} && p[1] == pair{1, 2} && p[2] == pair{2, 1}){
            if(x != 1 && y != 1)
                cout << "NO\n";
            else
                cout << "YES\n";
            continue;
        }
        if(p[0] == pair{1, n - 1} && p[1] == pair{1, n} && p[2] == pair{2, n}){
            if(x != 1 && y != n)
                cout << "NO\n";
            else
                cout << "YES\n";
            continue;
        }
        if(p[0] == pair{n - 1, 1} && p[1] == pair{n, 1} && p[2] == pair{n, 2}){
            if(x != n && y != 1)
                cout << "NO\n";
            else
                cout << "YES\n";
            continue;
        }
        if(p[0] == pair{n - 1, n} && p[1] == pair{n, n - 1} && p[2] == pair{n, n}){
            if(x != n && y != n)
                cout << "NO\n";
            else
                cout << "YES\n";
            continue;
        }

        x += p[0].first + p[1].first + p[2].first;
        y += p[0].second + p[1].second + p[2].second;

        if((x % 2) == 0 && (y % 2) == 0)
            cout << "NO\n";
        else
            cout << "YES\n";
    }
}