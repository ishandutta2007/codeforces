#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        int a[100005];
        for(int i = 0; i < n; i++) cin >> a[i];
        bool f = false;
        if(n == 1 && a[0] == k) f = true;
        bool fr[100005]{0}, fl[100005]{0};
        int d = 0;
        for(int i = 0; i < n - 1; i++){
            if(a[i] >= k) d++;
            else d--;
            if(d >= 0){
                fl[i + 1] = true;
            }
            d = max(d, 0);
        }
        d = 0;
        for(int i = n - 1; i > 0; i--){
            if(a[i] >= k) d++;
            else d--;
            if(d >= 0){
                fr[i - 1] = true;
            }
            d = max(d, 0);
        }
        for(int i = 0; i < n; i++){
            if(a[i] >= k && (fl[i] || fr[i])) f = true;
        }
        bool g = false;
        for(int i = 0; i < n; i++){
            if(a[i] == k) g = true;
        }
        if(f && g) cout << "yes" << endl;
        else cout << "no" << endl;
    }
}