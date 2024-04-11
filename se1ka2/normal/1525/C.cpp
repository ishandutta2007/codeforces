#include <algorithm>
#include <iostream>
#include <stack>
using namespace std;
typedef pair<int, int> P;

int main()
{
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        int x[300005];
        for(int i = 0; i < n; i++) cin >> x[i];
        P q[300005];
        for(int i = 0; i < n; i++) q[i] = P(x[i], i);
        sort(q, q + n);
        char c[300005];
        for(int i = 0; i < n; i++) cin >> c[i];
        int ans[300005];
        for(int i = 0; i < n; i++) ans[i] = -1;
        for(int p = 0; p < 2; p++){
            stack<P> st;
            for(int k = 0; k < n; k++){
                int i = q[k].second;
                if(x[i] % 2 != p) continue;
                if(c[i] == 'R') st.push(P(x[i], i));
                else if(st.empty()) st.push(P(-x[i], i));
                else{
                    int d = st.top().first, j = st.top().second;
                    st.pop();
                    ans[i] = ans[j] = (x[i] - d) / 2;
                }
            }
            while((int)st.size() >= 2){
                P t[2];
                t[0] = st.top();
                st.pop();
                t[1] = st.top();
                st.pop();
                int i = t[0].second, j = t[1].second;
                ans[i] = ans[j] = m - (t[0].first + t[1].first) / 2;
            }
        }
        for(int i = 0; i < n; i++) cout << ans[i] << " ";
        cout << endl;
    }
}