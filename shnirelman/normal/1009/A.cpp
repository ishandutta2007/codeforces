#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n, m;
    cin >> n >> m;

    vector<int> a(n), b(m);
    for(int i = 0; i < n; i++)cin >> a[i];
    for(int j = 0; j < m; j++)cin >> b[j];

    int ans = 0, ind = 0;
    for(int i = 0; i < n; i++){
        if(ind == m)break;
        if(a[i] <= b[ind]){
            ans++;
            ind++;
        }

    }

    cout << ans;

}