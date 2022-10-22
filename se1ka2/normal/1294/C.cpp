#include <algorithm>
#include <iostream>
using namespace std;
typedef pair<int, int> P;

int main()
{
    int t;
    cin >> t;
    for(int w = 0; w < t; w++){
        int n;
        cin >> n;
        int ans[3]{0};
        for(int i = 2; i * i * i < n; i++){
            if(n % i == 0){
                n /= i;
                ans[0] = i;
                break;
            }
        }
        for(int i = ans[0] + 1; i * i < n; i++){
            if(n % i == 0){
                n /= i;
                ans[1] = i;
                break;
            }
        }
        if(ans[0] > 0 && ans[1] > 0){
            cout << "YES" << endl;
            cout << ans[0] << " " << ans[1] << " " << n << endl;
        }
        else cout << "NO" << endl;
    }
}