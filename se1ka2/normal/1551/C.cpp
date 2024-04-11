#include <algorithm>
#include <iostream>
using namespace std;

const int INF = 100000000;

string s[200005];

int main()
{
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        for(int i = 0; i < n; i++) cin >> s[i];
        int ans = -1;
        for(int c = 0; c < 5; c++){
            int d[200005];
            for(int i = 0; i < n; i++){
                d[i] = 0;
                for(int j = 0; j < (int)s[i].size(); j++){
                    if(s[i][j] == char('a' + c)) d[i]++;
                    else d[i]--;
                }
            }
            sort(d, d + n, greater<int>());
            d[n] = -INF;
            int x = 0;
            for(int i = 0; i <= n; i++){
                x += d[i];
                if(x <= 0){
                    ans = max(ans, i);
                    break;
                }
            }
        }
        cout << ans << endl;
    }
}