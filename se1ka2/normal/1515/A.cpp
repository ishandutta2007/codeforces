#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--){
        int n, x;
        cin >> n >> x;
        int w[102];
        for(int i = 0; i < n; i++) cin >> w[i];
        int s[102];
        s[0] = 0;
        for(int i = 1; i <= n; i++) s[i] = s[i - 1] + w[i - 1];
        if(s[n] == x){
            cout << "NO" << endl;
        }
        else{
            cout << "YES" << endl;
            for(int i = 1; i < n; i++){
                if(s[i] == x){
                    swap(w[i - 1], w[i]);
                    break;
                }
            }
            for(int i = 0; i < n; i++) cout << w[i] << " ";
            cout << endl;
        }
    }
}