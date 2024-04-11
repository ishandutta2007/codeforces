#include <algorithm>
#include <iostream>
using namespace std;

int main()
{
    int k;
    cin >> k;
    for(int c = 0; c < k; c++){
        int n;
        cin >> n;
        int a[1002] {0};
        for(int i = 0; i < n; i++) cin >> a[i];
        sort(a, a + n, greater<int>());
        int ans = 0;
        for(int i = 0; i < n; i++){
            if(a[i] >= i + 1){
                ans = i + 1;
            }
            else break;
        }
        cout << ans << endl;
    }
}