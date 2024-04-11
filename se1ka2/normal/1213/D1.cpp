#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> v[200003];
    for(int i = 0; i < n; i++){
        int a;
        cin >> a;
        int now = 0;
        while(a > 0){
            v[a].push_back(now);
            a /= 2;
            now++;
        }
    }
    int ans = 1000000000;
    for(int i = 0; i <= 200000; i++){
        if((int)v[i].size() < k) continue;
        int sum = 0;
        sort(v[i].begin(), v[i].end());
        for(int j = 0; j < k; j++) sum += v[i][j];
        ans = min(ans, sum);
    }
    cout << ans << endl;
}