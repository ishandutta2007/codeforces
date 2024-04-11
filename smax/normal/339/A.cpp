#include <bits/stdc++.h>
using namespace std;

int main() {
    int index=0;
    char a[100];
    string s;
    cin >> s;
    for (int i=0; i<s.length(); i++)
        if (s[i] != '+')
            a[index++] = s[i];
    sort(a, a+index);
    for (int i=0; i<index-1; i++)
        cout << a[i] << "+";
    cout << a[index-1] << endl;
    
    return 0;
}