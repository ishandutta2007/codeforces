#include <algorithm>
#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    int d[6];
    cout << "and 1 2" << endl;
    cin >> d[0];
    cout << "and 1 3" << endl;
    cin >> d[1];
    cout << "and 2 3" << endl;
    cin >> d[2];
    cout << "or 1 2" << endl;
    cin >> d[3];
    cout << "or 1 3" << endl;
    cin >> d[4];
    cout << "or 2 3" << endl;
    cin >> d[5];
    int a[10005]{0};
    for(int i = 30; i >= 0; i--){
        if(((d[0] >> i) & 1) || ((d[1] >> i) & 1) || (((d[3] >> i) & (d[4] >> i) & 1) && !((d[5] >> i) & 1))) a[0] ^= (1 << i);
        if(((d[0] >> i) & 1) || ((d[2] >> i) & 1) || (((d[3] >> i) & (d[5] >> i) & 1) && !((d[4] >> i) & 1))) a[1] ^= (1 << i);
        if(((d[1] >> i) & 1) || ((d[2] >> i) & 1) || (((d[4] >> i) & (d[5] >> i) & 1) && !((d[3] >> i) & 1))) a[2] ^= (1 << i);
    }
    for(int i = 3; i < n; i++){
        int c[2];
        cout << "and 1 " << i + 1 << endl;
        cin >> c[0];
        cout << "or 1 " << i + 1 << endl;
        cin >> c[1];
        int x = c[1] - c[0];
        a[i] = (a[0] ^ x);
    }
    sort(a, a + n);
    cout << "finish " << a[k - 1] << endl;
}