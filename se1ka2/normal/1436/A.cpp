#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        for(int i = 0; i < n; i++){
            int a;
            cin >> a;
            m -= a;
        }
        if(m == 0) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}