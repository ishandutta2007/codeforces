#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int a[200005];
    int b[200005] {0};
    for(int i = 0; i < n; i++){
        cin >> a[i];
        b[a[i]]++;
    }
    for(int i = 200000; i > 0; i--){
        if(b[i] >= 1 && b[i + 1] == 0){
            b[i + 1]++;
            b[i]--;
        }
        if(b[i] >= 2){
            b[i - 1]++;
            b[i]--;
        }
    }
    int ans = 0;
    for(int i = 200000; i > 0; i--) if(b[i]) ans++;
    cout << ans << endl;
}