#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int ans = (1 << 30) - 1;
        for(int i = 0; i < n; i++){
            int a;
            cin >> a;
            ans &= a;
        }
        cout << ans << endl;
    }
}