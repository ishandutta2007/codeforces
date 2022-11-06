#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 1e5+5;

int a[sz];

int main()
{
    int t;
    cin >> t;
    while(t--) {
        int n, k;
        scanf("%d %d", &n, &k);
        set <int> st;
        for(int i=0; i<n; i++) scanf("%d", &a[i]), st.insert(a[i]);
        if(st.size() > k) puts("-1");
        else {
            printf("%d\n", n * k);
            for(int i=1; i<=n && st.size() < k; i++) {
                st.insert(i);
            }

            for(int i=0; i<n; i++) {
                for(auto x : st) printf("%d ", x);
            }
            puts("");
        }
    }
}