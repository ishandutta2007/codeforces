#include <bits/stdc++.h>
using namespace std;
int id[1000000];
int mod=998244353;
int main()
{
    int q;
    cin>>q;
    int l=0,r=1;
    while(q--)
    {
        char t;
        cin>>t;
        int x;
        cin>>x;
        if (t=='L')
        {
            id[x]=l--;
        }
        else if (t=='R')
        {
            id[x]=r++;
        }
        else
        {
            cout<<min(id[x]-l,r-id[x])-1<<endl;
        }
    }
}