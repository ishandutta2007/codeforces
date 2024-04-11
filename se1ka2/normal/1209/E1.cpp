#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;
typedef pair<int, int> P;
typedef pair<int, P> PP;
 
int main()
{
    int t;
    cin >> t;
    for(int c = 0; c < t; c++){
        int n, m;
        cin >> n >> m;
        priority_queue<PP> que;
        int a[5][102];
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                cin >> a[i][j];
                que.push(PP(a[i][j], P(j, i)));
            }
        }
        int lar[6] {0};
        P arglar[6];
        for(int i = 0; i < min(n * m, n + 2); i++){
            PP pp = que.top();
            que.pop();
            lar[i] = pp.first;
            arglar[i] = pp.second;
        }
        int ans = 0;
        for(int i = 0; i < n; i++) ans += lar[i];
        if(n == 4 && m != 1){
            if((arglar[0].first == arglar[3].first && arglar[0].first == arglar[4].first && arglar[1].first == arglar[2].first &&
                abs(arglar[3].second - arglar[4].second) == 2 && abs(arglar[1].second - arglar[2].second) == 2) ||
               (arglar[1].first == arglar[3].first && arglar[1].first == arglar[4].first && arglar[2].first == arglar[0].first &&
                abs(arglar[3].second - arglar[4].second) == 2 && abs(arglar[2].second - arglar[0].second) == 2) ||
               (arglar[2].first == arglar[3].first && arglar[2].first == arglar[4].first && arglar[0].first == arglar[1].first &&
                abs(arglar[3].second - arglar[4].second) == 2 && abs(arglar[0].second - arglar[1].second) == 2)){
                ans = max(ans - lar[2] + lar[4], ans - lar[3] + lar[5]);
            }
            else{
                sort(arglar, arglar + n);
                if(arglar[0].first == arglar[1].first && arglar[2].first == arglar[3].first &&
                   (abs(arglar[0].second - arglar[1].second) + abs(arglar[2].second - arglar[3].second)) % 2 == 1){
                    ans = ans - lar[3] + lar[4];
                }
            }
        }
        cout << ans << endl;
    }
}