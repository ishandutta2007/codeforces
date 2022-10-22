#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        int p[102];
        for(int i = 0; i < n; i++) p[i] = i + 1;
        if(k > (n - 1) / 2){
            cout << -1 << endl;
            continue;
        }
        for(int i = 0; i < k; i++) swap(p[i * 2 + 1], p[i * 2 + 2]);
        for(int i = 0; i < n; i++) cout << p[i] << " ";
        cout << endl;
    }
}