#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while(t--){
        string s;
        cin >> s;

        int cnt = 0;
        for(int i = 0; i < s.size(); ++i){
            if(s[i] == 'A') cnt++;
            else{
                if(cnt) cnt--;
                else cnt++;
            }
        }

        cout << cnt << "\n";
    }
}