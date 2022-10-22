#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int a[300005];
        for(int i = 0; i < n; i++) cin >> a[i];
        if(a[0] < a[n - 1]) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}