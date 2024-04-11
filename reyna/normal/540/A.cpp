//In the name of God
#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    string S,P;
    cin >> S >> P;
    int ans = 0;
    for(int i = 0; i < n;i++){
        ans += min(abs(S[i] - P[i]),min(abs(S[i] + 10 - P[i]),abs(S[i] - 10 - P[i])));
    }
    cout << ans << endl;
    return 0;
}