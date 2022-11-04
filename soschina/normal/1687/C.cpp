#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <set>
using namespace std;
const int N = 2e5 + 2;

int t, n, m, l[N], r[N];
int cnt[N];
long long a[N], b[N];
vector<int> vec[N];

set<int> st;
queue<int> q;

int main(){
    scanf("%d", &t);
    while(t--){
        memset(cnt + 1, 0, sizeof(int) * m);
        q = queue<int>();
        st.clear();
        scanf("%d%d", &n, &m);
        for (int i = 0; i <= n; i++){
            st.insert(i);
            vec[i].clear();
        }
        for (int i = 1; i <= n; i++)
            scanf("%lld", &a[i]);
        for (int i = 1; i <= n; i++)
            scanf("%lld", &b[i]);
        q.push(0);
        st.erase(0);
        for (int i = 1; i <= n; i++){
            a[i] += a[i - 1];
            b[i] += b[i - 1];
            if(a[i] == b[i]){
                q.push(i);
                st.erase(i);
            }
        }
        for (int i = 1; i <= m; i++){
            scanf("%d%d", &l[i], &r[i]);
            vec[l[i] - 1].push_back(i);
            vec[r[i]].push_back(i);
        }
        while(!q.empty()){
            int pos = q.front();
            q.pop();
            for(int id : vec[pos]){
                cnt[id]++;
                if(cnt[id] == 2){
                    auto it = st.lower_bound(l[id]);
                    while(it != st.end() && *it <= r[id]){
                        q.push(*it);
                        it = st.erase(it);
                    }
                }
            }
        }
        puts(st.empty() ? "YES" : "NO");
    }
    return 0;
}