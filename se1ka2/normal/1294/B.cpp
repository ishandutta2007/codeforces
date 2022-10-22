#include <algorithm>
#include <iostream>
using namespace std;
typedef pair<int, int> P;

int main()
{
    int t;
    cin >> t;
    for(int w = 0; w < t; w++){
        int n;
        cin >> n;
        P p[1002];
        p[0] = P(0, 0);
        for(int i = 1; i <= n; i++){
            int x, y;
            cin >> x >> y;
            p[i] = P(x, y);
        }
        sort(p, p + n + 1);
        P ans[1002];
        bool f = true;
        for(int i = 0; i < n; i++){
            ans[i] = P(p[i + 1].first - p[i].first, p[i + 1].second - p[i].second);
            if(ans[i].first < 0 || ans[i].second < 0){
                f = false;
                break;
            }
        }
        if(!f) cout << "NO" << endl;
        else{
            cout << "YES" << endl;
            for(int i = 0; i < n; i++){
                for(int j = 0; j < ans[i].first; j++) cout << 'R';
                for(int j = 0; j < ans[i].second; j++) cout << 'U';
            }
            cout << endl;
        }
    }
}