#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int c[3]{0};
        for(int i = 0; i < n; i++){
            int a;
            cin >> a;
            c[a % 3]++;
        }
        int ans = 0;
        for(int i = 0; i < 12; i++){
            if(c[i % 3] > n / 3){
                ans += c[i % 3] - n / 3;
                c[(i + 1) % 3] += c[i % 3] - n / 3;
                c[i % 3] = n / 3;
            }
        }
        cout << ans << endl;
    }
}