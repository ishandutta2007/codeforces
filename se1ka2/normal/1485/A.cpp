#include <iostream>
using namespace std;

const int INF = 1000000000;

int main()
{
    int t;
    cin >> t;
    while(t--){
        int a, b;
        cin >> a >> b;
        int ans = INF;
        for(int i = 0; i < 100; i++){
            if(b + i <= 1) continue;
            int s = a, c = i;
            while(s){
                s /= (b + i);
                c++;
            }
            ans = min(ans, c);
        }
        cout << ans << endl;
    }
}