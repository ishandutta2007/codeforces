#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main()
{
    int n;
    cin >> n;
    map<int, vector<int>> mp;
    int a[200005];
    for(int i = 0; i < n; i++){
        cin >> a[i];
        mp[a[i]].push_back(i);
    }
    int d[200005];
    int last[200005];
    for(int i = 0; i < n; i++){
        if(upper_bound(mp[a[i] - 1].begin(), mp[a[i] - 1].end(), i) == mp[a[i] - 1].begin()){
            last[i] = -1;
            d[i] = 1;
        }
        else{
            last[i] = *(upper_bound(mp[a[i] - 1].begin(), mp[a[i] - 1].end(), i) - 1);
            d[i] = d[last[i]] + 1;
        }
    }
    int ans = 0;
    int l = -1;
    for(int i = 0; i < n; i++){
        if(d[i] > ans){
            ans = d[i];
            l = i;
        }
    }
    cout << ans << endl;
    vector<int> v;
    while(l != -1){
        v.push_back(l);
        l = last[l];
    }
    for(int i = (int)v.size() - 1; i >= 0; i--) cout << v[i] + 1 << " ";
    cout << endl;
}