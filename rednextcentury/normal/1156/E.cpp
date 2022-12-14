#include<bits/stdc++.h>
using namespace std;
int b[1000000];
int a[1000000];
int L[1000000];
int R[1000000];
int main()
{
    int n;
    cin>>n;
    for (int i=0;i<n;i++)
    {
        cin>>b[i];
        a[b[i]]=i;
    }
    stack<int> st;
    for (int i=0;i<n;i++)
    {
        while(!st.empty())
        {
            if (b[i]>=b[st.top()])
                st.pop();
            else break;
        }
        if (st.empty())
            L[i]=0;
        else
            L[i]=st.top()+1;
        st.push(i);
    }
    while(!st.empty())st.pop();
    for (int i=n-1;i>=0;i--)
    {
        while(!st.empty())
        {
            if (b[i]>b[st.top()])
                st.pop();
            else break;
        }
        if (st.empty())
            R[i]=n-1;
        else
            R[i]=st.top()-1;
        st.push(i);
    }
    int ret=0;
    for (int i=0;i<n;i++)
    {
        int l1=i-L[i];
        int l2=R[i]-i;
        if (l1<l2){
            for (int j=i-1;j>=L[i];j--)
                if (a[b[i]-b[j]]>=i && a[b[i]-b[j]]<=R[i])ret++;
        } else
            for (int j=i+1;j<=R[i];j++)
                if (a[b[i]-b[j]]<=i && a[b[i]-b[j]]>=L[i])ret++;
    }
    cout<<ret<<endl;
}