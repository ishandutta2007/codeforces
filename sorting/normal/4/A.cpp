#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int w;
    cin >> w;

    if(w > 2 && w % 2 == 0)
        cout << "YES\n";
    else
        cout << "NO\n";
}