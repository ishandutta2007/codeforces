#include <algorithm>
#include <iostream>
using namespace std;

int main()
{
    int n, a, b, k;
    cin >> n >> a >> b >> k;
    int h[200005];
    for(int i = 0; i < n; i++){
        cin >> h[i];
        h[i] = ((h[i] - 1) % (a + b)) / a;
    }
    sort(h, h + n);
    int s = 0;
    int i = 0;
    for(; i < n; i++){
        s += h[i];
        if(s > k) break;
    }
    cout << i << endl;
}