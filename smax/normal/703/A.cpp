#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m = 0, c = 0;
    cin >> n;
    for (int i=0; i<n; i++) {
        int mi, ci;
        cin >> mi >> ci;
        if (mi > ci)
            m++;
        else if (mi < ci)
            c++;
    }
    if (m > c)
        cout << "Mishka" << endl;
    else if (m < c)
        cout << "Chris" << endl;
    else
        cout << "Friendship is magic!^^" << endl;
    
    return 0;
}