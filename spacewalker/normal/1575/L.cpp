#include <bits/stdc++.h>

using namespace std;
int lis(vector<int> &a) {
    if (a.empty()) return 0;
    vector<int> tail((long)(a.size()), 0);
    tail[0] = a[0];
    int len = 1;
    for (long i = 1; i < a.size(); i++) {
        auto it = upper_bound(tail.begin(), tail.begin() + len, a[i]);
        if (it == tail.begin() + len) {
            tail[len++] = a[i];
        } else *it = a[i];
    }
    return len;
}

int main() { 
    int n;cin>>n;
    vector<pair<int,int>> arr(n);
    for (int i=0; i < n; i++) {
        int x;cin>>x;
        int y = i+1-x;
        arr[i] = {x, -y};
    }
    sort(arr.begin(), arr.end());
    vector<int> farr;
    for (auto [x,y]: arr){
       if (y > 0) continue;
        farr.push_back(-y);
    }
    cout<<lis(farr)<<"\n";
}