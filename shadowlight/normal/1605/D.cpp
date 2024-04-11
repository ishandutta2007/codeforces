/**
 * the_hyp0cr1t3
 * 24.09.2021 01:19:28
**/
#ifdef W
    #include <k_II.h>
#else
    #include <bits/stdc++.h>
    using namespace std;
#endif
 
template<class T> class Y {
    T f;
public:
    template<class U> explicit Y(U&& f): f(forward<U>(f)) {}
    template<class... Args> decltype(auto) operator()(Args&&... args) {
        return f(ref(*this), forward<Args>(args)...);
    }
}; template<class T> Y(T) -> Y<T>;
 
int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int Q; cin >> Q;
 
    while(Q--) []() {
        int i, j, k, n;
        cin >> n;
        vector<vector<int>> g(n);
        for(i = 0; i < n - 1; i++) {
            int u, v; cin >> u >> v;
            g[--u].push_back(--v); g[v].push_back(u);
        }
 
        int lg = 32 - __builtin_clz(n);
        vector<vector<int>> vals(lg);
        for(i = 1; i <= n; i++)
            vals[31 - __builtin_clz(i)].push_back(i);
 
        vector<int> col(n);
        Y([&](auto dfs, int v, int p) -> void {
            for(auto& x: g[v]) if(x ^ p) {
                col[x] = col[v] ^ 1;
                dfs(x, v);
            }
        })(0, -1);
 
        int w = accumulate(col.begin(), col.end(), 0);
        if(w > n - w) {
            w = n - w;
            for(auto& x: col) x ^= 1;
        }
 
        vector<int> ans(n);
        for(i = j = k = 0; k < lg; k++) {
            for(auto x: vals[k]) {
                if(w >> k & 1) {
                    while(!col[i]) i++;
                    ans[i++] = x;
                } else {
                    while(col[j]) j++;
                    ans[j++] = x;
                }
            }
        }
 
        for(i = 0; i < n; i++)
            cout << ans[i] << " \n"[i + 1 == n];
    }();
 
} // ~W