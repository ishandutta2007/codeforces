#include <iostream>
using namespace std;
int n, m, k;
int main()
{
    cin >> n >> m >> k;
    int a, b; char c;
    a = (k + 2*m - 1) / (2*m); // col
    b = k % (2*m);
    if(b == 0) b = 2*m;
    b = (b+1) / 2;
    if(k % 2) c = 'L';
    else c = 'R';
    cout << a << " " << b << " " << c << endl;
}