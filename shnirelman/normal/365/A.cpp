#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n, k;
    cin >> n >> k;

    int ans = 0;

    for(int i = 0; i < n; i++){
        string s;
        cin >> s;

        vector<bool> b(k + 1, false);
        for(int j = 0; j < s.length(); j++)
            if(s[j] - '0' <= k)b[s[j] - '0'] = true;

        bool flag = true;
        for(int j = 0; j <= k; j++)if(!b[j])flag = false;

        ans += flag;
    }

    cout << ans;
}