#include <algorithm>
#include <iostream>
#include <set>
using namespace std;
typedef long long ll;

int main()
{
    int t;
    cin >> t;
    for(int c = 0; c < t; c++){
        ll n;
        cin >> n;
        set<int> st;
        for(ll i = 1; i * i <= n * 2; i++){
            st.insert(n / i);
        }
        cout << (int)st.size() + *st.begin() << endl;;
        for(int i = 0; i < *st.begin(); i++) cout << i << " ";
        for(auto itr = st.begin(); itr != st.end(); itr++) cout << *itr << " ";
        cout << endl;
    }
}