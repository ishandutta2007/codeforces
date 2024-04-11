#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q;
    cin >> n >> q;
    int a[300005];
    for(int i = 0; i < n; i++) cin >> a[i];
    while(q--){
        int t;
        cin >> t;
        for(int i = 0; i < n; i++){
            if(a[i] == t){
                cout << i + 1 << " ";
                for(int j = i; j > 0; j--) a[j] = a[j - 1];
                a[0] = t;
                break;
            }
        }
    }
    cout << endl;
}