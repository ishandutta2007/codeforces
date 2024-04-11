#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int a[100005];
    for(int i = 0; i < n; i++) cin >> a[i];
    int b[100005]{0};
    for(int i = 1; i < n; i++){
        if(a[i] == a[i - 1]) b[i] = 1;
    }
    int ans = 0;
    int last = -1;
    for(int i = 0; i < n; i++){
        if(!b[i]) ans++;
        else{
            if(last == -1 || a[i] != a[last]) ans++;
            else{
                for(int j = last + 1; j < i - 1; j++){
                    if(a[j] != a[i] && a[j + 1] != a[i]){
                        ans++;
                        break;
                    }
                }
            }
            last = i;
        }
    }
    cout << ans << endl;
}