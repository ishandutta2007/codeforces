#include <iostream>
#include <set>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        set<int> st;
        for (int i = 0; i < 2; i++)
        {
            string s;
            cin >> s;
            st.insert(s[0]);
            st.insert(s[1]);
        }
        cout << (int)st.size() - 1 << endl;
    }
}