#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    string s1, s2;
    cin >> n >> s1 >> s2;
    
    int ret = 0;
    for (int i=0; i<n; i++)
        ret += min(abs((int)(s1[i]-'0')-(int)(s2[i]-'0')), 10-abs((int)(s1[i]-'0')-(int)(s2[i]-'0')));
    
    cout << ret << endl;
    
    return 0;
}