#include <iostream>
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    int d = 1;
    int l = k;
    while(l < n){
        l *= k;
        d++;
    }
    cout << d << endl;
    for(int u = 0; u < n; u++){
        for(int v = u + 1; v < n; v++){
            int s = u, t = v;
            for(int i = 0; i < d; i++){
                if(s % k < t % k){
                    cout << i + 1 << " ";
                    break;
                }
                s /= k; t /= k;
            }
        }
    }
    cout << endl;
}