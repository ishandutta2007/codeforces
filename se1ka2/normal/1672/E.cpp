#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int left = 0, right = n * 2001;
    while(right - left > 1){
        int mid = (right + left) / 2;
        cout << "? " << mid << endl;
        int h;
        cin >> h;
        if(h == 1) right = mid;
        else left = mid;
    }
    int w = right;
	int ans = w;
    for(int i = 1; i <= n; i++){
        cout << "? " << w / i << endl;
        int h;
        cin >> h;
        if(h) ans = min(ans, (w / i) * h);
    }
    cout << "! " << ans << endl;
}