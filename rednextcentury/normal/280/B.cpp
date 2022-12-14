#include <bits/stdc++.h>
using namespace std;
int a[1000000];
int ans=0;
void solve(int n)
{
    stack<int> st;
    for (int i=0;i<n;i++)
    {
        while(!st.empty() && a[i]>st.top())
            st.pop();
        if (!st.empty())
            ans=max(ans,a[i]^st.top());
        st.push(a[i]);
    }
}
int main()
{
    int n;;
    scanf("%d",&n);
    for (int i=0;i<n;i++)
        scanf("%d",&a[i]);
    solve(n);
    reverse(a,a+n);
    solve(n);
    cout<<ans<<endl;
}