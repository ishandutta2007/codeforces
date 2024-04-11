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
        int a[200005], b[200005];
        for(int i = 0; i < n; i++) cin >> a[i] >> b[i];
        int left = 0, right = n + 1;
        while(right - left > 1){
            int mid = (right + left) / 2;
            int c = 0;
            for(int i = 0; i < n; i++){
                if(b[i] >= c && a[i] >= mid - c - 1) c++;
            }
            if(c >= mid) left = mid;
            else right = mid;
        }
        cout << left << endl;
    }
}