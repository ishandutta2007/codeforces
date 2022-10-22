#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        bool b[200005];
        for(int i = 0; i <= n; i++) b[i] = false;
        int u = n;
        vector<int> v;
        v.push_back(u);
        while(u > 2){
            for(int i = 0; i < u; i++){
                if(i * i >= u){
                    b[i] = true;
                    v.push_back(i);
                    u = i;
                }
            }
        }
        vector<int> ans[2];
        for(int i = 2; i < n; i++){
            if(!b[i]){
                ans[0].push_back(i);
                ans[1].push_back(n);
            }
        }
        for(int i = 1; i < (int)v.size(); i++){
            ans[0].push_back(v[i - 1]);
            ans[1].push_back(v[i]);
            ans[0].push_back(v[i - 1]);
            ans[1].push_back(v[i]);
        }
        cout << (int)ans[0].size() << endl;
        for(int i = 0; i < (int)ans[0].size(); i++) cout << ans[0][i] << " " << ans[1][i] << endl;
    }
}