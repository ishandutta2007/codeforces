#include <iostream>
using namespace std;
typedef long long ll;

ll ans[502][502];

int main()
{
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        string c[502];
        for(int i = 0; i < n; i++) cin >> c[i];
        for(int i = n - 1; i >= 0; i--){
            for(int j = 0; j < m; j++){
                if(c[i][j] == '.') ans[i][j] = 0;
                else if(i == n - 1 || j == 0 || j == m - 1) ans[i][j] = 1;
                else ans[i][j] = min(min(ans[i + 1][j - 1], ans[i + 1][j]), ans[i + 1][j + 1]) + 1;
            }
        }
        ll s = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++) s += ans[i][j];
        }
        cout << s << endl;
    }
}