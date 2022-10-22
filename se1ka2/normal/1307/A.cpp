#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    for(int c = 0; c < t; c++){
        int n, d;
        cin >> n >> d;
        int a[102];
        for(int i = 0; i < n; i++) cin >> a[i];
        int ans = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < a[i]; j++){
                if(d >= i){
                    d -= i;
                    ans++;
                }
            }
        }
        cout << ans << endl;
    }
}