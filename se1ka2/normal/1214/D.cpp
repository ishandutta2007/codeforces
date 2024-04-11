#include <iostream>
#include <vector>
#include <stack>
using namespace std;
typedef pair<int, int> P;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<char>> s(n, vector<char>(m));
    vector<vector<bool>> used(n, vector<bool>(m));
    for(int i = 0; i < n; i++) for(int j = 0; j < m; j++){
        cin >> s[i][j];
        used[i][j] = false;
    }
    int ans = 0;
    stack<P> st;
    for(int c = 0; c < 2; c++){
        st.push(P(0, 0));
        while(st.size()){
            P p = st.top();
            st.pop();
            int i = p.first, j = p.second;
            if(i == n - 1 && j == m - 1){
                ans++;
                break;
            }
            used[i][j] = true;
            if(j < m - 1 && s[i][j + 1] != '#' && !used[i][j + 1]) st.push(P(i, j + 1));
            if(i < n - 1 && s[i + 1][j] != '#' && !used[i + 1][j]) st.push(P(i + 1, j));
        }
        while(st.size()) st.pop();
    }
    cout << ans << endl;
}