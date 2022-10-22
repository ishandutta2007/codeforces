#include <iostream>
#include <set>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int q;
    cin >> q;
    while(q--){
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        int d[1000007];
        int l = 0;
        for(int i = n - 1; i >= n - k; i--){
            if(s[i] == '1') l = min(l + 1, k);
            else l = 0;
        }
        d[n - k] = l;
        for(int i = n - k - 1; i >= 0; i--){
            if(s[i] == '1') l = min(l + 1, k);
            else l = 0;
            d[i] = l;
        }
        set<int> st;
        for(int i = 0; i <= n - k; i++){
            if(k - d[i] >= 20) continue;
            int x = 0;
            for(int j = 0; j < min(20, k); j++){
                if(s[i + k - 1 - j] == '0') x += (1 << j);
            }
            st.insert(x);
        }
        int i = 0;
        for(auto itr = st.begin();; itr++){
            if(itr == st.end()){
                if(k > 20 || i < (1 << k)){
                    cout << "YES\n";
                    for(int j = 0; j < k - min(20, k); j++) cout << 0;
                    for(int j = min(20, k) - 1; j >= 0; j--){
                        if((i >> j) & 1) cout << 1;
                        else cout << 0;
                    }
                    cout << "\n";
                }
                else{
                    cout << "NO\n";
                }
                break;
            }
            if(*itr != i){
                cout << "YES\n";
                for(int j = 0; j < k - min(20, k); j++) cout << 0;
                for(int j = min(20, k) - 1; j >= 0; j--){
                    if((i >> j) & 1) cout << 1;
                    else cout << 0;
                }
                cout << "\n";
                break;
            }
            i++;
        }
    }
}