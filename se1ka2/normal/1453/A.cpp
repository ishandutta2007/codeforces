#include <iostream>
#include <set>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        set<int> st;
        for(int i = 0; i < n; i++){
            int a;
            cin >> a;
            st.insert(a);
        }
        for(int i = 0; i < m; i++){
            int a;
            cin >> a;
            st.insert(a);
        }
        cout << n + m - (int)st.size() << endl;
    }
}