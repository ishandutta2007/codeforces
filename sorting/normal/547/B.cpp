#include<iostream>
#include<stack>

using namespace std;

int a[200002],l[200002],r[200002],arr[200002];
stack<int> st;

int main ()
{
    int n,i,maxi=0,p;

    cin>>n;

    for(i=0;i<n;i++)cin>>a[i];

    for(i=0;i<n;i++)
    {
        while(!st.empty() && a[st.top()]>=a[i])st.pop();

        if(st.empty())l[i]=-1;
        else l[i]=st.top();
        st.push(i);
    }

    while(!st.empty())st.pop();

    for(i=n-1;i>=0;i--)
    {
        while(!st.empty() && a[st.top()]>=a[i])st.pop();

        if(st.empty())r[i]=n;
        else r[i]=st.top();
        st.push(i);
    }

    for(i=0;i<n;i++)
    {
        p=r[i]-l[i]-1;
        //cout<<a[i]<<" "<<arr[p]<<" "<<l[i]<<" "<<r[i]<<endl;
        arr[p]=max(arr[p],a[i]);
    }

    for(i=n;i>=1;i--)
    {
        maxi=max(arr[i],maxi);
        arr[i]=maxi;
    }

    for(i=1;i<n;i++)cout<<arr[i]<<" ";
    cout<<arr[i]<<endl;

    return 0;
}