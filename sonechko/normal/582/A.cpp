#include<bits/stdc++.h>
using namespace std;
#define pb push_back
int main()
{
    int n;
    cin>>n;
    multiset<int> st;
    for (int i=1; i<=n*n; i++)
        {
            int l;
            cin>>l;
            st.insert(l);
        }
    vector<int> v;
    for (int i=1; i<=n; i++)
    {
        int k=*st.rbegin();
        st.erase(st.find(k));
        for (int j=0; j<v.size(); j++)
        {
            int kk=__gcd(k,v[j]);
            st.erase(st.find(kk));
            st.erase(st.find(kk));
        }
        v.pb(k);
        cout<<k<<" ";
    }
    cout<<endl;
}