#include <iostream>
#include <set>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--){
        string a, b;
        cin >> a >> b;
        int n = a.size(), m = b.size();
        set<string> st;
        for(int i = 0; i < n; i++){
            for(int j = i; j <= n; j++) st.insert(a.substr(i, j - i));
        }
        int ans = 0;
        for(int i = 0; i < m; i++){
            for(int j = i; j <= m; j++){
                string t = b.substr(i, j - i);
                if(st.find(t) != st.end()) ans = max(ans, (j - i) * 2);
            }
        }
        cout << n + m - ans << endl;
    }
}