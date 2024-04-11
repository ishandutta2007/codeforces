#include <bits/stdc++.h>
using namespace std;
stack<pair<long long,bool> > st;
long long mx = (1LL<<32)-1;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    pair<long long,bool> res = {0,0};
    int l;
    cin>>l;
    st.push({1,0});
    for (int i=0;i<l;i++)
    {
        string s;
        cin>>s;
        if (s=="for") {
            long long x;
            cin>>x;
            auto p = st.top();
            if (mx/p.first < x) st.push({p.first,1});
            else st.push({p.first*x,p.second});
        } else if (s=="add") {
            auto p = st.top();
            if (p.second)res.second=1;
            if (res.first + p.first > mx) res.second = true;
            else res.first = res.first+p.first;
        } else {
            st.pop();
        }
    }
    if (res.second)cout<<"OVERFLOW!!!"<<endl;
    else cout<<res.first<<endl;
}