#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    int a[300000];
    int b[300000];
    cin >> n;
    int coua=0, coub=0;
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
        if (a[i] > b[i])
            coua++;
        else
            coub++;
    }
    vector<pair<int,int>> ans;
    bool ab;
    if (coua >= coub) {
        ab = true;
        for (int i = 0; i < n; i++) {
            if (a[i] > b[i]) {
                ans.push_back(pair<int,int>(a[i],i+1));
            }
        }
    }
    else {
        ab = false;
        for (int i = 0; i < n; i++) {
            if (a[i] < b[i]) {
                ans.push_back(pair<int,int>(b[i],i+1));
            }
        }
    }
    sort(ans.begin(), ans.end());
    if (!ab)
        reverse(ans.begin(), ans.end());
    cout << max(coua, coub) << endl;
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i].second <<  " ";
    cout << endl;
    return 0;
}