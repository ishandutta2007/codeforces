#include <algorithm>
#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int a[100005];
        int b[100005];
        for(int i = 0; i < n; i++) b[i] = 0;
        for(int i = 0; i < n; i++){
            cin >> a[i];
            a[i]--;
            b[a[i]]++;
        }
        sort(b, b + n, greater<int>());
        int i;
        for(i = 0; i < n; i++){
            if(b[i] != b[0]) break;
        }
        for(int j = 0; j < n; j++){
            if((b[0] - 1) * (j + 1) + i > n){
                cout << j - 1 << endl;
                break;
            }
        }
    }
}