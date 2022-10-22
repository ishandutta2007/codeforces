#include <algorithm>
#include <iostream>
using namespace std;
typedef pair<int, int> P;

int main()
{
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int b[200005]{0};
        for(int i = 0; i < n; i++){
            int a;
            cin >> a;
            if(b[a] == 0) b[a] = i + 1;
            else b[a] = -1;
        }
        bool f = false;
        for(int i = 1; i <= n; i++){
            if(b[i] > 0){
                cout << b[i] << endl;
                f = true;
                break;
            }
        }
        if(!f) cout << -1 << endl;
    }
}