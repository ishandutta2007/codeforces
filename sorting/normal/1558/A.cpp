#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while(t--){
        int a[2];
        cin >> a[0] >> a[1];
        vector<int> ans;
        for(int i = 0; i < 2; ++i){
            int b[2];
            b[0] = b[1] = (a[0] + a[1]) >> 1;
            b[i] += (a[0] + a[1]) & 1;
            int c[2];
            if(b[0] < a[0]){
                c[1] = a[0] - b[0];
                c[0] = 0;
            }
            else{
                c[0] = a[1] - b[1];
                c[1] = 0;
            }

            while(c[0] <= b[0] && c[1] <= b[1]){
                ans.push_back(c[0] + c[1]);
                ++c[0], ++c[1];
            }
        }
        sort(ans.begin(), ans.end());
        ans.resize(unique(ans.begin(), ans.end()) - ans.begin());

        cout << ans.size() << "\n";
        for(int x: ans)
            cout << x << " ";
        cout << "\n";
    }
}