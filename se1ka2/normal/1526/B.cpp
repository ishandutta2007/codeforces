#include <iostream>
using namespace std;

bool b[2000];

void rec(int n){
    if(n > 1500) return;
    if(b[n]) return;
    b[n] = true;
    rec(n + 11);
    rec(n + 111);
}

int main()
{
    rec(0);
    int t;
    cin >> t;
    while(t--){
        int x;
        cin >> x;
        if(x >= 1300 || b[x]) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}