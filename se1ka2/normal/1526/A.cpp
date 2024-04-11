#include <algorithm>
#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        n *= 2;
        int a[52];
        for(int i = 0; i < n; i++) cin >> a[i];
        sort(a, a + n);
        for(int i = 0; i < n / 2; i++) cout << a[i] << " " << a[n - 1 - i] << " ";
        cout << endl;
    }
}