#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
typedef pair<int, int> P;

const int INF = 100000000;

int main()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    int x, y;
    cin >> x >> y;
    if(abs(x) + abs(y) > n || abs(x + y) % 2 != n % 2){
        cout << -1 << endl;
        return 0;
    }
    int nx = x, ny = y;
    P p[200005];
    for(int i = n - 1; i >= 0; i--){
        p[i + 1] = P(nx, ny);
        if(s[i] == 'R') nx--;
        if(s[i] == 'L') nx++;
        if(s[i] == 'U') ny--;
        if(s[i] == 'D') ny++;
    }
    p[0] = P(nx, ny);
    int j = 0;
    nx = 0, ny = 0;
    int ans = INF;
    for(int i = 0; i < n; i++){
        for(; j <= n; j++){
            if(abs(p[j].first - nx) + abs(p[j].second - ny) <= j - i){
                ans = min(ans, j - i);
                break;
            }
        }
        if(s[i] == 'R') nx++;
        if(s[i] == 'L') nx--;
        if(s[i] == 'U') ny++;
        if(s[i] == 'D') ny--;
    }
    cout << ans << endl;
}