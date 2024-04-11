#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int t;
    cin >> t;

    for(int i = 0; i < t; i++){
        int n;
        cin >> n;
        string s;
        cin >> s;

        bool ans = true;
        for(int j = 0; j < n / 2; j++)
            if(s[j] != s[n - j - 1] && abs(int(s[j]) - int(s[n - j - 1])) != 2){
                ans = false;

            }
        if(ans)cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}