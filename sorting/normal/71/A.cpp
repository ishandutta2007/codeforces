#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    while(n--){
        string s;
        cin >> s;
        if(s.size() <= 10) cout << s << "\n";
        else cout << s[0] << s.size() - 2 << s.back() << "\n";
    }
}