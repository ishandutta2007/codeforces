#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 11;
int pref1[N],next1[N],firs;
int main()
{
    string s;
    cin>>s;
    int firs=1,k=1;
    for (int i=0; i<s.size()-1; i++)
    {
        if (s[i]=='l')
        {
            int pr=pref1[k];
            if (pr!=0) {next1[pr]=i+2; pref1[i+2]=pr;} else firs=i+2;
            pref1[k]=i+2;
            next1[i+2]=k;
            k=i+2;
        } else
        {
            int ne=next1[k];
            if (ne!=0) {pref1[ne]=i+2; next1[i+2]=ne;}
            next1[k]=i+2;
            pref1[i+2]=k;
            k=i+2;
        }
    }
    for (int i=1; i<=s.size(); i++)
    {
        cout<<firs<<"\n";
        firs=next1[firs];
    }
    cout<<endl;
}