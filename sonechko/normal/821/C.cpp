#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define ss second
#define ld long double
#define pb push_back
#define ff first
const int N = 3e5 + 11;
const int M = 1e9;
vector<int> v[N];
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    int pf=n+1;
    set<int> st;
    st.insert(n+1);
    vector<int> v;
    int ans=0;
    for (int i=1; i<=2*n; i++)
    {
        string s;
        cin>>s;
        if (s=="add")
        {
            int k;
            cin>>k;
            st.insert(k);
            v.pb(k);
        } else
        if (s=="remove")
        {
            if (v.size()!=0&&*st.begin()!=v[v.size()-1])
            {
                ans++;
                v.clear();
            }
            st.erase(*st.begin());
            pf=*st.begin();
            if (v.size()>0) v.pop_back();
        }
    }
    cout<<ans<<endl;
}