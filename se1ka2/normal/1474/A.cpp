#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        string b;
        cin >> b;
        int ans[100005];
        for(int i = 0; i < n; i++){
            if(i == 0) ans[i] = 1;
            else if(b[i] + 1 == b[i - 1] + ans[i - 1]) ans[i] = 0;
            else ans[i] = 1;
        }
        for(int i = 0; i < n; i++) cout << ans[i];
        cout << endl;
    }
}