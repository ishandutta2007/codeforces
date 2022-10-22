#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int n;
    cin >> n;

    vector<int> a(n), b(n);
    for(int i = 0; i < n; i++)cin >> a[i] >> b[i];

    int ans = 0;
    for(int i = 0; i < n; i++){
        bool flag = false;
        for(int j = 0; j < n && !flag; j++)
            if(j != i && b[j] == a[i])flag = true;
        ans += !flag;
    }

    cout << ans;
}