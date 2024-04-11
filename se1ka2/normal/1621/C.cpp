#include <iostream>
#include <set>
using namespace std;

int query(int i){
    cout << "? " << i + 1 << endl;
    int c;
    cin >> c;
    c--;
    return c;
}

int main()
{
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        set<int> st;
        for(int i = 0; i < n; i++) st.insert(i);
        int ans[10005];
        while(st.size()){
            int l = *st.begin();
            while(true){
                int c = query(l);
                if(c == l) break;
            }
            int last = l;
            while(true){
                int x = query(l);
                ans[last] = x;
                st.erase(last);
                last = x;
                if(last == l) break;
            }
        }
        cout << "!";
        for(int i = 0; i < n; i++) cout << " " << ans[i] + 1;
        cout << endl;
    }
}