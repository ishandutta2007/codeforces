#include <algorithm>
#include <iostream>
using namespace std;
typedef pair<int, int> P;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        P p[200005];
        for(int i = 0; i < m; i++){
            int r, c;
            cin >> r >> c;
            p[i] = P(--c, --r);
        }
        p[m++] = P(n, 0);
        p[m++] = P(n, 1);
        sort(p, p + m);
        bool odd[2]{0};
        bool f = true;
        for(int i = 0; i < m; i++){
            if(i < m - 1 && p[i].first == p[i + 1].first){
                if(odd[0] ^ odd[1]){
                    f = false;
                    break;
                }
                i++;
            }
            else{
                for(int j = 0; j < 2; j++){
                    if(p[i].second == j){
                        if(!(p[i].first % 2 == odd[j]) && (odd[0] ^ odd[1])){
                            f = false;
                            break;
                        }
                        if(odd[j] != odd[1 - j]){
                            odd[j] = (p[i].first + 1) % 2;
                            odd[1 - j] = odd[j];
                        }
                        else{
                            odd[j] = (p[i].first + 1) % 2;
                            odd[1 - j] = !odd[j];
                        }
                    }
                }
                if(!f) break;
            }
        }
        if(f) cout << "YES\n";
        else cout << "NO\n";
    }
}