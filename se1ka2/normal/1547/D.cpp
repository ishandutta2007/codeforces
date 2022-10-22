#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int x[200005];
        for(int i = 0; i < n; i++) cin >> x[i];
        int y[200005];
        for(int i = 0; i < n; i++) y[i] = 0;
        for(int i = 1; i < n; i++){
            for(int j = 0; j < 30; j++){
                if(!((x[i] >> j) & 1) && ((x[i - 1] >> j) & 1)){
                    x[i] ^= (1 << j);
                    y[i] ^= (1 << j);
                }
            }
        }
        for(int i = 0; i < n; i++) cout << y[i] << " ";
        cout << endl;
    }
}