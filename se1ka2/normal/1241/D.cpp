#include <iostream>
#include <vector>
#include <set>
using namespace std;

int a[300004];
int b[300004];
int dif[300004];

int main()
{
    int q;
    cin >> q;
    for(int c = 0; c < q; c++){
        int n;
        cin >> n;
        set<int> st;
        st.insert(n + 1);
        fill(b, b + n + 1, 0);
        for(int i = 0; i < n; i++){
            scanf("%d", &a[i]);
            dif[a[i]] = *(st.upper_bound(a[i]));
            st.insert(a[i]);
            b[a[i]] = 1;
        }
        vector<int> v;
        for(int i = 0; i <= n; i++) if(b[i]){
            v.push_back(i);
        }
        v.push_back(n + 1);
        int ans = 1;
        int now = 1;
        for(int i = 0; i < (int)v.size() - 1; i++){
            if(dif[v[i]] != v[i + 1]) now++;
            else now = 1;
            ans = max(ans, now);
        }
        cout << (int)v.size() - 1 - ans << endl;
    }
}