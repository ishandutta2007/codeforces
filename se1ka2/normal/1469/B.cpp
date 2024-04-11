#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--){
        int l[2]{0};
        for(int i = 0; i < 2; i++){
            int n;
            cin >> n;
            int s = 0;
            for(int j = 0; j < n; j++){
                int a;
                cin >> a;
                s += a;
                l[i] = max(l[i], s);
            }
        }
        cout << l[0] + l[1] << endl;
    }
}