#include <bits/stdc++.h>
using namespace std;

int main() {
    int v1, v2, t, d, d1[100], d2[100];
    cin >> v1 >> v2 >> t >> d;
    
    d1[0] = v1;
    for (int i=1; i<t; i++)
        d1[i] = d1[i-1] + d;
    d2[t-1] = v2;
    for (int i=t-2; i>=0; i--)
        d2[i] = d2[i+1] + d;
    
    int ret = 0;
    for (int i=0; i<t; i++)
        ret += min(d1[i], d2[i]);
    
    cout << ret << endl;
    
    return 0;
}