#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main(){
    int n;
    cin >> n;

    vector<int> a(n);
    for(int i = 0; i < n; i++)cin >> a[i];

    vector<int> cnt(100001, 0);
    set<int> s;
    for(int i = 1; i < n; i++){
        s.insert(a[i - 1]);
        cnt[a[i]] = s.size();
    }

    long long ans = 0;
    for(int i = 0; i < cnt.size(); i++)ans += cnt[i];

    cout << ans;
}