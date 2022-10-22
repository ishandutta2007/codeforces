#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    int p[12];
    p[0] = 1;
    for(int i = 1; i < 10; i++) p[i] = p[i - 1] * 10 + 1;
    while(t--){
        int n;
        cin >> n;
        int ans = 0;
        for(int i = 0; i < 10; i++){
            for(int j = 1; j < 10; j++){
                if(p[i] * j > n) break;
                ans++;
            }
        }
        cout << ans << endl;
    }
}