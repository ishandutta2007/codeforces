#include <bits/stdc++.h>
using namespace std;
set<int> A,B;
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,k;
    string s;
    cin>>n>>k>>s;
    for (int i=0;i<s.size();i++)
    {
        if (s[i]=='0')A.insert(i);
        else B.insert(i);
    }
    if (A.empty() || B.empty())
    {
        cout<<"tokitsukaze"<<endl;
        return 0;
    }
    if ((*A.rbegin()-*A.begin())<k || (*B.rbegin()-*B.begin())<k)
    {
        cout<<"tokitsukaze"<<endl;
        return 0;
    }
    set<int> TA=A,TB=B;
    for (int i=0;i<k;i++)
    {
        if (s[i]=='0')A.erase(i);
        else B.erase(i);
        A.insert(i);
    }
    if ((*A.rbegin()-*A.begin())>=k && (*B.rbegin()-*B.begin())>=k)
    {
        cout<<"once again"<<endl;
        return 0;
    }
    for (int i=k;i<n;i++)
    {
        A.erase(i-k);
        if (s[i-k]=='0')A.insert(i-k);
        else B.insert(i-k);
        if (s[i]=='0')A.erase(i);
        else B.erase(i);
        A.insert(i);
        if ((*A.rbegin()-*A.begin())>=k && (*B.rbegin()-*B.begin())>=k)
        {
            cout<<"once again"<<endl;
            return 0;
        }
    }
    A=TA,B=TB;
    for (int i=0;i<k;i++)
    {
        if (s[i]=='0')A.erase(i);
        else B.erase(i);
        B.insert(i);
    }
    if ((*A.rbegin()-*A.begin())>=k && (*B.rbegin()-*B.begin())>=k)
    {
        cout<<"once again"<<endl;
        return 0;
    }
    for (int i=k;i<n;i++)
    {
        B.erase(i-k);
        if (s[i-k]=='0')A.insert(i-k);
        else B.insert(i-k);
        if (s[i]=='0')A.erase(i);
        else B.erase(i);
        B.insert(i);
        if ((*A.rbegin()-*A.begin())>=k && (*B.rbegin()-*B.begin())>=k)
        {
            cout<<"once again"<<endl;
            return 0;
        }
    }
    cout<<"quailty"<<endl;
}