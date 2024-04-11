#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <map>
using namespace std;
typedef pair<int, int> P;

int main()
{
    int n, m;
    cin >> n >> m;
    map<P, int> mp;
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        mp[P(a, b)] = 1;
        mp[P(b, a)] = 1;
    }
    set<int> st;
    for(int i = 0; i < n; i++) st.insert(i);
    int ans = -1;
    while(st.size()){
        queue<int> que;
        int i = *st.begin();
        que.push(i);
        st.erase(i);
        while(que.size()){
            int now = que.front();
            que.pop();
            auto itr = st.begin();
            while(itr != st.end()){
                int next = *itr;
                itr++;
                if(mp[P(now, next)] == 0){
                    que.push(next);
                    st.erase(next);
                }
            }
        }
        ans++;
    }
    cout << ans << endl;
}