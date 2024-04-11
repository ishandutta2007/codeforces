#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--){
        int n;
        string s;
        cin >> n >> s;
        vector<int> v;
        for(int i = 0; i < n; i++){
            if(s[i] == '2') v.push_back(i);
        }
        char ans[202][202];
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(i == j) ans[i][j] = 'X';
                else ans[i][j] = '=';
            }
        }
        int k = v.size();
        if(k == 1 || k == 2){
            cout << "NO" << endl;
            continue;
        }
        cout << "YES" << endl;
        for(int i = 0; i < k; i++){
            ans[v[i]][v[(i + 1) % k]] = '+';
            ans[v[(i + 1) % k]][v[i]] = '-';
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++) cout << ans[i][j];
            cout << endl;
        }
    }
}