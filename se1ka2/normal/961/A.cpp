#include <iostream>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    int c[1002];
    int h[1002]{0};
    for(int i = 0; i < m; i++){
        cin >> c[i];
        c[i]--;
        h[c[i]]++;
    }
    int l = 1002;
    for(int i = 0; i < n; i++) l = min(l, h[i]);
    cout << l << endl;
}