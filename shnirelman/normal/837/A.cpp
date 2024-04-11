#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n;
    cin >> n;

    string s;
    getline(cin, s);
    getline(cin, s);

    int ans = 0;
    for(int i = 0; i < n; i++){
        int k = 0;
        for(; i < n && s[i] != ' '; i++){
            if(s[i] >= 'A' && s[i] <= 'Z')k++;
        }

        ans = max(ans, k);
    }

    cout << ans;
}