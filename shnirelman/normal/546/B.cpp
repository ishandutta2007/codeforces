#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int n;
    cin >> n;

    vector<int> cnt(n * 2 + 1, 0);
    for(int i = 0; i < n; i++){
        int b;
        cin >> b;
        cnt[b]++;
    }

    int ans = 0;
    for(int i = 1; i < cnt.size(); i++)
        if(cnt[i] > 1){
            ans += cnt[i] - 1;
            cnt[i + 1] += cnt[i] - 1;
        }

    cout << ans;
}