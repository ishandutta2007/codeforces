#include <iostream>
using namespace std;

bool fined[100002];

int main()
{
    int n;
    cin >> n;
    int a[100002], b[100002];
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) cin >> b[i];
    int now = 0;
    int ans = 0;
    for(int i = 0; i < n; i++){
        if(fined[a[i]]) continue;
        while(a[i] != b[now]){
            fined[b[now]] = true;
            now++;
            ans++;
        }
        now++;
    }
    cout << ans << endl;
}