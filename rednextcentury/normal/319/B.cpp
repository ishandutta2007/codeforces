# include<bits/stdc++.h>
using namespace std;
int a[1000000];
stack<int> st;
int t[1000000];
int main()
{
    int n;
    cin>>n;
    for (int i=0;i<n;i++)
        cin>>a[i];
    st.push(0);
    t[0]=-1;
    int ans=0;
    for (int i=1;i<n;i++)
    {
        while(!st.empty())
        {
            int x=st.top();
            if (a[x]>a[i])
                break;
            t[i]=max(t[i],t[x]+1);
            st.pop();
        }
        if (st.empty())
            t[i]=-1;
        ans=max(ans,t[i]+1);
        st.push(i);
    }
    cout<<ans<<endl;
}