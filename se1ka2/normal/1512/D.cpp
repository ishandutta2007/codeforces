#include <algorithm>
#include <iostream>
using namespace std;
typedef long long ll;

int main()
{
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        ll b[200005];
        for(int i = 0; i < n + 2; i++) cin >> b[i];
        sort(b, b + n + 2);
        ll s = 0;
        for(int i = 0; i < n; i++) s += b[i];
        if(s == b[n]){
            for(int i = 0; i < n; i++) cout << b[i] << " ";
            cout << endl;
            continue;
        }
        s += b[n];
        int i;
        for(i = 0; i <= n; i++){
            if(s - b[i] == b[n + 1]) break;
        }
        if(i == n + 1){
            cout << -1 << endl;
            continue;
        }
        for(int j = 0; j < i; j++) cout << b[j] << " ";
        for(int j = i + 1; j <= n; j++) cout << b[j] << " ";
        cout << endl;
    }
}