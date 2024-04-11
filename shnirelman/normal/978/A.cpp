#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n;
    cin >> n;

    vector<int> a(n);
    for(int i = 0; i < n; i++)cin >> a[i];

    vector<bool> b(1013, false);
    vector<int> ans;
    for(int i = n - 1; i >= 0; i--){
        if(!b[a[i]]){
            ans.push_back(a[i]);
            b[a[i]] = true;
        }
    }

    cout << ans.size() << endl;
    for(int i = ans.size() - 1; i >= 0; i--)cout << ans[i] << ' ';
}