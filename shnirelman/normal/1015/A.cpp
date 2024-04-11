#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n, m;
    cin >> n >> m;

    vector<bool> a(m + 1, false);
    for(int i = 0; i < n; i++){
        int l, r;
        cin >> l >> r;
        for(int j = l; j <= r; j++)a[j] = true;
    }

    int ans = 0;
    for(int i = 1; i <= m; i++)
        if(!a[i])ans++;

    cout << ans << endl;
    for(int i = 1; i <= m; i++)
        if(!a[i])cout << i << ' ';

}