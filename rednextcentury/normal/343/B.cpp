#include<bits/stdc++.h>
using namespace std;
int main()
{
    stack<char> st;
    string s;
    cin>>s;
    for (int i=0;i<s.size();i++)
    {
        if (st.empty())st.push(s[i]);
        else if (st.top()==s[i])st.pop();
        else st.push(s[i]);
    }
    if (!st.empty())printf("No\n");
    else
    printf("Yes\n");
}