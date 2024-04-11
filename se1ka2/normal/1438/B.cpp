#include <iostream>
#include <set>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        set<int> st;
        for(int i = 0; i < n; i++){
            int b;
            cin >> b;
            st.insert(b);
        }
        if((int)st.size() == n) cout << "NO" << endl;
        else cout << "YES" << endl;
    }
}