#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for(int i = 0; i < n; i++)cin >> a[i];

    for(int i = n; i < k; i++)a.push_back(0);

    int ans = 0;
    vector<int> ind(k);
    for(int i = 0; i < k; i++){
        int m = 0;
        for(int j = 1; j < a.size(); j++)
            if(a[m] < a[j])m = j;

        ans += a[m];
        a[m] = -1;
        ind[i] = m;
    }

    cout << ans << endl;

    sort(ind.begin(), ind.end());
    if(k > 1){
        cout << ind[0] + 1 << ' ';
        for(int i = 1; i < k - 1; i++)cout << ind[i] - ind[i - 1] << ' ';
        cout << n - ind[k - 2] - 1 << endl;
    }
    else cout << n;

}