#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    for (int i=0; i<n-1; i++)
        cout << (i % 2 == 0 ? "I hate" : "I love") << " that ";
    cout << (n % 2 == 0 ? "I love" : "I hate") << " it" << endl;
    
    return 0;
}