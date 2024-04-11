#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    int n, m;
    cin >> n >> m;

    vector<int> cnt(101, 0);
    for(int i = 0; i < m; i++){
        int a;
        cin >> a;
        cnt[a]++;
    }

    int ans = 0;
    for(int i = 1; i <= 100; i++){
        bool flag = false;
        int k = 0;
        for(int j = 0; j < cnt.size(); j++)k += cnt[j] / i;

        if(k >= n)ans = i;
        else break;
    }

    cout << ans;
}