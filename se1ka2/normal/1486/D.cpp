#include <iostream>
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    int a[200005];
    for(int i = 0; i < n; i++) cin >> a[i];
    int left = 0, right = n + 1;
    while(right - left > 1){
        int mid = (right + left) / 2;
        int b[200005];
        for(int i = 0; i < n; i++){
            if(a[i] >= mid) b[i] = 1;
            else b[i] = -1;
        }
        int s[200005];
        s[0] = 0;
        for(int i = 1; i <= n; i++) s[i] = s[i - 1] + b[i - 1];
        int l[200005];
        l[0] = 0;
        for(int i = 1; i <= n; i++) l[i] = min(l[i - 1], s[i]);
        bool f = false;
        for(int i = k; i <= n; i++){
            if(s[i] - l[i - k] >= 1) f = true;
        }
        if(f) left = mid;
        else right = mid;
    }
    cout << left << endl;
}