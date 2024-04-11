#include <iostream>
using namespace std;

int c[102][102];

int main()
{
    int n, m;
    cin >> n >> m;
    int a[102], b[102];
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < m; i++) cin >> b[i];
    int r = 0, l = 0;
    for(int i = 1; i < n; i++){
        c[i][0] = a[i];
        r ^= a[i];
    }
    for(int j = 1; j < m; j++){
        c[0][j] = b[j];
        l ^= b[j];
    }
    if((r ^ b[0]) != (l ^ a[0])){
        cout << "NO" << endl;
        return 0;
    }
    cout << "YES" << endl;
    c[0][0] = r ^ b[0];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++) cout << c[i][j] << " ";
        cout << endl;
    }
}