#include <iostream>
#include <vector>
using namespace std;

void set(int from, int to, int cost, vector<int> *ans){
    ans[0].push_back(from);
    ans[1].push_back(to);
    ans[2].push_back(cost);
}

int main()
{
    int l, r;
    cin >> l >> r;
    int d = r - l + 1;
    int k;
    for(k = 20; k >= 0; k--){
        if((d >> k) & 1) break;
    }
    k++;
    vector<int> ans[3];
    for(int i = 0; i < k; i++){
        for(int j = i + 1; j <= k; j++){
            int t = j;
            if(t == k) t++;
            if(i == 0) set(i, t, 1, ans);
            else set(i, t, (1 << (i - 1)), ans);
        }
    }
    set(k, k + 1, 1, ans);
    int s = -1;
    for(int i = 0; i < k - 1; i++){
        if((d >> i) & 1){
            set(i + 1, k, (1 << (k - 1)) + s, ans);
            s += (1 << i);
        }
    }
    int n = k + 2;
    if(l > 1){
        n++;
        set(k + 1, k + 2, l - 1, ans);
    }
    int m = ans[0].size();
    cout << "YES" << endl;
    cout << n << " " << m << endl;
    for(int i = 0; i < m; i++) cout << ans[0][i] + 1 << " " << ans[1][i] + 1 << " " << ans[2][i] << endl;
}