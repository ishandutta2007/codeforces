#include <iostream>
#include <queue>
using namespace std;
typedef pair<int, int> P;

int main()
{
    int t;
    cin >> t;
    while(t--){
        int n, x, y;
        cin >> n >> x >> y;
        int a[100005];
        int d[100005]{0};
        vector<int> v[100005];
        priority_queue<P> que;
        for(int i = 0; i < n; i++){
            scanf("%d", &a[i]);
            d[a[i]]++;
            v[a[i]].push_back(i);
        }
        int r;
        for(int i = 1; i <= n + 1; i++){
            if(d[i]) que.push(P(d[i], i));
            else r = i;
        }
        int ans[100005];
        for(int i = 0; i < n; i++) ans[i] = -1;
        for(int i = 0; i < x; i++){
            P p = que.top();
            que.pop();
            int u = p.second;
            int j = v[u].back();
            v[u].pop_back();
            ans[j] = u;
            d[u]--;
            if(d[u]) que.push(P(d[u], u));
        }
        priority_queue<P> que2;
        for(int i = 1; i <= n + 1; i++){
            if(d[i]) que2.push(P(d[i], i));
        }
        int g[100005], h[100005];
        int c = 0;
        while(que2.size()){
            P p = que2.top();
            for(int i = c; i < c + p.first; i++){
                g[i] = v[p.second].back();
                v[p.second].pop_back();
            }
            c = c + p.first;
            que2.pop();
        }
        int l = c;
        for(int i = 1; i < c; i++){
            if(a[g[i]] != a[g[i - 1]]){
                l = i;
                break;
            }
        }
        for(int i = l; i < l + c; i++) h[i % c] = a[g[i - l]];
        int j = 0;
        while(a[g[j]] == h[j]) j++;
        int e = x;
        while(e < y && j < c){
            ans[g[j]] = h[j];
            j++;
            e++;
        }
        if(e < y){
            printf("NO\n");
            continue;
        }
        printf("YES\n");
        for(int i = 0; i < n; i++){
            if(ans[i] == -1) ans[i] = r;
        }
        for(int i = 0; i < n; i++) printf("%d ", ans[i]);
        printf("\n");
    }
}