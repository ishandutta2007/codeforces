
 #include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    string s;
    cin>>s;
    int first = -1,last=-1;
    int dot=-1;
    for (int i=0;i<s.size();i++)
    {
        if (s[i]=='.')dot=i;
        if (s[i]>'0' && s[i]!='.' && first==-1)
            first = i;
        if (s[i]>'0' && s[i]!='.')
            last = i;
    }
    if (dot==-1)
        dot = s.size();
    int afterE = dot-first;
    if (afterE>0)afterE--;
    cout<<s[first];
    if (first!=last)cout<<'.';
    for (int i=first+1;i<=last;i++)
        if (s[i]!='.')
            cout<<s[i];
    if (afterE!=0)
        cout<<"E"<<afterE<<endl;
}