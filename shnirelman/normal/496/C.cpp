#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main(){
    int n, m;
    cin >> n >> m;

    vector<string> s(n);
    for(int i = 0; i < n; i++)cin >> s[i];

    bool flag = true;
    int ans = 0;
    while(flag){
        flag = false;
        for(int i = 0; i < n - 1; i++){
            for(int j = 0; j < s[i].length(); j++)
                if(s[i][j] < s[i + 1][j])break;
                else if(s[i][j] > s[i + 1][j]){
                    flag = true;
                    for(int l = 0; l < n; l++)
                        s[l].erase(s[l].begin() + j, s[l].begin() + j + 1);
                    ans++;
                    break;
                }
        }
    }

    cout << ans;

}