#include <algorithm>
#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int h[200005];
        for(int i = 0; i < n; i++) cin >> h[i];
        sort(h, h + n);
        int l = 0;
        for(int i = 1; i < n - 1; i++){
            if(h[i + 1] - h[i] < h[l + 1] - h[l]) l = i;
        }
        cout << h[l] << " ";
        for(int i = l + 2; i < n; i++) cout << h[i] << " ";
        for(int i = 0; i < l; i++) cout << h[i] << " ";
        cout << h[l + 1] << endl;
    }
}