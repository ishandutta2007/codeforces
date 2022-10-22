#include <algorithm>
#include <iostream>
using namespace std;
typedef pair<int, int> P;

int main()
{
    int t;
    cin >> t;
    P p[100005];
    while(t--){
        int n, k;
        cin >> n >> k;
        int a[100005];
        for(int i = 0; i < n; i++) cin >> a[i];
        for(int i = 0; i < n; i++) p[i] = P(a[i], i);
        sort(p, p + n);
        for(int i = 0; i < n; i++){
            if(i == 0 || p[i].second != p[i - 1].second + 1) k--;
        }
        if(k >= 0) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
}