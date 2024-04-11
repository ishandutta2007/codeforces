#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    for(int c = 0; c < t; c++){
        int n;
        cin >> n;
        int l[100005], r[100005];
        int ll = 1000000001, rr = -1;
        for(int i = 0; i < n; i++){
            cin >> l[i] >> r[i];
            ll = min(ll, r[i]);
            rr = max(rr, l[i]);
        }
        cout << max(0, rr - ll) << endl;
    }
}