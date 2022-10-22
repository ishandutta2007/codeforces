#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int n, m;
    cin >> n >> m;

    vector<pair<int, int> > a(n, make_pair(0, 0));
    long long sum = 0;
    for(int i = 0; i < n; i++){
        int a1, b1;
        cin >> a1 >> b1;
        sum += a1;
        a[i].second = a1;
        a[i].first = a1 - b1;
    }
    
    sort(a.begin(), a.end());

    int ans = 0;
    int i = n - 1;
    while(i >= 0 && sum > m){
        sum -= a[i].first;
        i--;
        ans++;
    }
    
    if(sum > m)cout << -1;
    else cout << ans;
}