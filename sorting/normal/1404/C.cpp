#include <bits/stdc++.h>

using namespace std;

const int k_N = 3e5 + 7;

struct Fenwick{
    int a[k_N];

    void update(int i, int d){
        for(i += 3; i < k_N; i += i & -i)
            a[i] += d;
    }

    int query(int i){
        int ans = 0;
        for(i += 3; i >= 1; i -= i & -i)
            ans += a[i];
        return ans;
    }
};

int n, q;
int a[k_N];
array<int, 2> queries[k_N];

vector<int> v[k_N];
int ans[k_N];

Fenwick f;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> q;

    for(int i = 1; i <= n; ++i){
        cin >> a[i];
        a[i] = i - a[i];
    }

    for(int i = 0; i < q; ++i){
        cin >> queries[i][0] >> queries[i][1];
        queries[i][0]++;
        queries[i][1] = n - queries[i][1];
    }

    for(int i = 0; i < q; ++i)
        v[queries[i][1]].push_back(i);

    for(int i = 1; i <= n; ++i){
        if(a[i] >= 0){
            int l = 0, r = i;
            while(l != r){
                int mid = (l + r + 1) >> 1;
                if(f.query(mid) >= a[i])
                    l = mid;
                else
                    r = mid - 1;
            }

            //cout << a[i] << " - " << l << endl;

            f.update(1, 1);
            f.update(l + 1, -1);
        }

        for(int idx: v[i])
            ans[idx] = f.query(queries[idx][0]);
    }

    for(int i = 0; i < q; ++i)
        cout << ans[i] << "\n";
}