#include <iostream>
using namespace std;
typedef long long ll;
 
int main()
{
    ll n, p;
    cin >> n >> p;
    ll b[40];
    b[0] = 1;
    for(int i = 1; i < 40; i++) b[i] = b[i - 1] * 2;
    for(int i = 1; i < 40; i++){
        int m = n - p * i;
        if(m < i){
            cout << -1 << endl;
            return 0;
        }
        int k = 0;
        for(int j = 39; j >= 0; j--){
            if(m >= b[j]){
                m -= b[j];
                k++;
            }
        }
        if(k <= i){
            cout << i << endl;
            return 0;
        }
    }
    cout << -1 << endl;
}