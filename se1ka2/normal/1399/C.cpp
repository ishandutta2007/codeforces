#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int w[52];
        int b[102]{0};
        for(int i = 0; i < n; i++){
            cin >> w[i];
            b[w[i]]++;
        }
        int ans = 0;
        for(int i = 2; i <= n * 2; i++){
            int s = 0;
            for(int j = 1; j * 2 < i; j++){
                s += min(b[j], b[i - j]);
            }
            if(i % 2 == 0) s += b[i / 2] / 2;
            ans = max(ans, s);
        }
        cout << ans << endl;
    }
}