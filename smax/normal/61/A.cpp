#include <bits/stdc++.h>
using namespace std;
 
int main() {
    string n1, n2, ret = "";
    cin >> n1 >> n2;
    for (int i=0; i<n1.length(); i++)
        ret += n1[i] != n2[i] ? '1' : '0';
    cout << ret << endl;
    
    return 0;
}