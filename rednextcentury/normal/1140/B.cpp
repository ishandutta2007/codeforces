#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        string s;
        cin>>s;
        int L=0,R=0;
        for (int i=0;i<s.size();i++){
            if (s[i]=='<')
                L++;
            else break;
        }
        for (int j=s.size()-1;j>=0;j--)
        {
            if (s[j]=='>')
                R++;
            else break;
        }
        cout<<min(L,R)<<endl;
    }
}