#include <iostream>
using namespace std;
int n; char s[222];
int main() {
    cin >> n; getchar();
    cin.getline(s, 202);

    int ans = 0, cnt = 0;
    for(int i=0;i<n;i++) {
        if(s[i] == ' ') cnt = 0;
        if(s[i] >= 'A' && s[i] <= 'Z') cnt ++;
        ans = max(ans, cnt);
    }
    cout << ans << endl;

}