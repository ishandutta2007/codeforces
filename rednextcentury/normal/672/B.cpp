#include <bits/stdc++.h>
using namespace std;
int a[100000];
int main ()
{
    int n;
    cin>>n;
    string s;
    cin>>s;
    if (s.size()>26)
        cout<<-1<<endl;
    else
    {
        int ret=0;
        for (int i=0;i<s.size();i++)
            if (++a[s[i]]>1) ret++;
        cout<<ret<<endl;
    }
}