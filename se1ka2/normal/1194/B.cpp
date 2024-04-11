#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    int q;
    cin >> q;
    for(int c = 0; c < q; c++){
        int n, m;
        cin >> n >> m;
        vector<string> s(n);
        vector<int> u(m);
        vector<int> r(n);
        for(int i = 0; i < n; i++){
            cin >> s[i];
            int sum = 0;
            for(int j = 0; j < m; j++) if(s[i][j] == '.') sum++;
            r[i] = sum;
        }
        for(int j = 0; j < m; j++){
            int sum = 0;
            for(int i = 0; i < n; i++) if(s[i][j] == '.') sum++;
            u[j] = sum;
        }
        int ans = 1000000;
        for(int i = 0; i < n; i++) for(int j = 0; j < m; j++){
            if(s[i][j] == '.') ans = min(ans, r[i] + u[j] - 1);
            else ans = min(ans, r[i] + u[j]);
        }
        cout << ans << endl;
    }
}