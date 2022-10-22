#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int a[102];
        int l = 0, r = 0;
        for(int i = 0; i < n; i++){
            cin >> a[i];
            if(a[i] > a[r]) r = i;
            if(a[i] < a[l]) l = i;
        }
        if(l > r) swap(l, r);
        cout << min(min(r + 1, n - l), l + 1 + n - r) << endl;
    }
}