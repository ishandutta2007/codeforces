#include <iostream>
#include <set>
using namespace std;

int main()
{
    int n;
    cin >> n;
    set<int> st;
    int a[103];
    for(int i = 0; i < n; i++){
        cin >> a[i];
        if(st.find(a[i]) != st.end()){
            i--;
            n--;
        }
        st.insert(a[i]);
    }
    int ans = n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(i == j) continue;
            if(a[i] % a[j] == 0){
                ans--;
                break;
            }
        }
    }
    cout << ans << endl;
}