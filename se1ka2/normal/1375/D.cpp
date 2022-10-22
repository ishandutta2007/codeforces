#include <algorithm>
#include <iostream>
#include <queue>
#include <set>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int a[1004];
        set<int> s[1004];
        set<int> st;
        for(int i = 0; i <= n; i++) st.insert(i);
        for(int i = 0; i < n; i++){
            cin >> a[i];
            s[a[i]].insert(i);
            st.erase(a[i]);
        }
        vector<int> ans;
        while(*st.begin() < n){
            int i = *st.begin();
            ans.push_back(i);
            s[a[i]].erase(i);
            if(s[a[i]].empty()) st.insert(a[i]);
            a[i] = i;
            st.erase(i);
        }
        for(int i = 0; i < n; i++){
            if(a[i] == i) continue;
            if(*st.begin() == i){
                ans.push_back(i);
                st.erase(i);
                st.insert(a[i]);
                a[i] = i;
                continue;
            }
            for(int j = 0; j < n; j++){
                if(a[j] == i){
                    ans.push_back(j);
                    ans.push_back(i);
                    a[j] = *st.begin();
                    st.erase(a[j]);
                    st.insert(a[i]);
                    a[i] = i;
                    break;
                }
            }
        }
        cout << (int)ans.size() << endl;
        for(int i : ans) cout << i + 1 << " ";
        cout << endl;
    }
}