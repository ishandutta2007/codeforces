#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int ans = 0;
        for(int i = 0; i < n; i++){
            int r;
            cin >> r;
            if(r != 2) ans++;
        }
        cout << ans << endl;
    }
}