#include <bits/stdc++.h>

using namespace std;
int main()
{
    string s;
    cin>>s;
    int n=s.size();
    int Q=0;
    int QA=0;
    int ret=0;
    for (int i=0;i<n;i++)
    {
        if (s[i]=='Q')ret+=QA,Q++;
        if (s[i]=='A')QA+=Q;
    }
    cout<<ret<<endl;
}