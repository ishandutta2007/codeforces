#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--){
        int k, n, m;
        cin >> k >> n >> m;
        int a[102], b[102];
        for(int i = 0; i < n; i++) cin >> a[i];
        for(int i = 0; i < m; i++) cin >> b[i];
        int i = 0, j = 0;
        vector<int> ans;
        while(i < n || j < m){
            if(i < n && a[i] <= k){
                ans.push_back(a[i]);
                if(a[i] == 0) k++;
                i++;
            }
            else if(j < m && b[j] <= k){
                ans.push_back(b[j]);
                if(b[j] == 0) k++;
                j++;
            }
            else break;
        }
        if((int)ans.size() < n + m) cout << -1 << endl;
        else{
            for(int i : ans) cout << i << " ";
            cout << endl;
        }
    }
}