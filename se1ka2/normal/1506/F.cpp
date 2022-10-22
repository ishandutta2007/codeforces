#include <algorithm>
#include <iostream>
using namespace std;
typedef pair<int, int> P;

P p[200005];

int main()
{
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        for(int i = 1; i <= n; i++){
            cin >> p[i].first;
            p[i].first--;
        }
        for(int i = 1; i <= n; i++){
            cin >> p[i].second;
            p[i].second--;
        }
        sort(p, p + n + 1);
        int ans = 0;
        for(int i = 1; i <= n; i++){
            if(p[i].second - p[i].first == p[i - 1].second - p[i - 1].first && (p[i].first + p[i].second) % 2 == 0){
                ans += p[i].second - p[i - 1].second;
            }
            else if((p[i - 1].first - p[i - 1].second) % 2){
                ans += ((p[i].first - p[i].second) - (p[i - 1].first - p[i - 1].second) + 1) / 2;
            }
            else{
                ans += ((p[i].first - p[i].second) - (p[i - 1].first - p[i - 1].second)) / 2;
            }
        }
        cout << ans << endl;
    }
}