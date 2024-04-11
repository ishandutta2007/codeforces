#include <bits/stdc++.h>
using namespace std;
void solve() {
    int n;cin>>n;
    vector<int> arr(10,-1);
    for (int i = 0; i < n; i++) {
        int b,d;cin>>b>>d;
        d--;
        arr[d] = max(arr[d], b);
    }
    int tot = 0;
    for (int i = 0; i < 10; i++) {
        if (arr[i] == -1) {
            cout<<"MOREPROBLEMS\n";return;
        }
        tot += arr[i];
    }
    cout<<tot<<"\n";
}
int main() {
    int tc;cin>>tc;
    for (int i= 0; i < tc; i++) {

        solve();
    }
    

}