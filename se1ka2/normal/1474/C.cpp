#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
using namespace std;

bool ok(int k, int n, int *a, int *ans0, int *ans1)
{
    bool b[2002];
    map<int, vector<int>> v;
    for(int i = 0; i < n - 1; i++){
        if(i == k) continue;
        b[i] = true;
        v[a[i]].push_back(i);
    }
    b[k] = false;
    b[n - 1] = false;
    int l = 0;
    ans0[l] = k;
    ans1[l] = n - 1;
    l++;
    int x = a[n - 1];
    int i = n - 1;
    while(true){
        while(!b[i] && i >= 0) i--;
        if(i < 0) break;
        int u = v[a[i]].back();
        v[a[i]].pop_back();
        b[u] = false;
        ans1[l] = u;
        if(v[x - a[i]].size()){
            int w = v[x - a[i]].back();
            v[x - a[i]].pop_back();
            b[w] = false;
            ans0[l] = w;
        }
        else{
            return false;
        }
        x = a[i];
        l++;
    }
    return true;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        n *= 2;
        int a[2002];
        for(int i = 0; i < n; i++) cin >> a[i];
        sort(a, a + n);
        bool f = false;
        for(int k = 0; k < n - 1; k++){
            int ans[2][2000];
            if(ok(k, n, a, ans[0], ans[1])){
                f = true;
                cout << "YES\n";
                cout << a[k] + a[n - 1] << "\n";
                for(int i = 0; i < n / 2; i++) cout << a[ans[0][i]] << " " << a[ans[1][i]] << "\n";
                break;
            }
        }
        if(!f) cout << "NO" << "\n";
    }
}