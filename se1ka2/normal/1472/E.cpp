#include <algorithm>
#include <iostream>
using namespace std;
typedef pair<int, int> P;
typedef pair<P, int> PP;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        PP p[400005];
        for(int i = 0; i < n; i++){
            int h, w;
            cin >> h >> w;
            p[i * 2] = PP(P(h, -w), i);
            p[i * 2 + 1] = PP(P(w, -h), i);
        }
        sort(p, p + n * 2);
        int ans[200005];
        for(int i = 0; i < n; i++) ans[i] = -2;
        int l = -2;
        int k = -2;
        for(int i = 0; i < n * 2; i++){
            if(l == -2 || -p[i].first.second <= k){
                l = p[i].second;
                k = -p[i].first.second;
            }
            else ans[p[i].second] = l;
        }
        for(int i = 0; i < n; i++) cout << ans[i] + 1 << " ";
        cout << "\n";
    }
}