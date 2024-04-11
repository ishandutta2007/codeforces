#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        int a[102];
        for(int i = 0; i < n; i++) cin >> a[i];
        for(int i = 0; i < n - 1; i++){
            int c = min(a[i], k);
            a[i] -= c;
            k -= c;
            a[n - 1] += c;
        }
        for(int i = 0; i < n; i++) cout << a[i] << " ";
        cout << endl;
    }
}