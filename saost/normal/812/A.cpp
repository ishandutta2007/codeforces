#include <iostream>
using namespace std;
int t, a[4][4], cnt[1005];
string s;
int main()
{
    for(int i=0; i<4; ++i)
    for(int j=0; j<4; ++j) cin >> a[i][j];
    for(int i=0; i<4; ++i) if (a[i][3] && (a[i][0] || a[i][1] || a[i][2] || a[(i+1)%4][0] || a[(i+2)%4][1] || a[(i+3)%4][2])) {
        cout << "YES";
        return 0;
    }
    cout << "NO";
}