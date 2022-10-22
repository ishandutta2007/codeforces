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
        int x[52];
        for(int i = 0; i < n; i++) cin >> x[i];
        set<int> st;
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++) st.insert(x[j] - x[i]);
        }
        cout << (int)st.size() << endl;
    }
}