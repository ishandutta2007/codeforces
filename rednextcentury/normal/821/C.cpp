#include<bits/stdc++.h>
using namespace std;
int st[1000000];
int sz=0;
bool comp(int a,int b)
{
    return a>b;
}
int sorted=0;
set<int> S;
int main()
{
    ios_base::sync_with_stdio(0);
    int n;
    cin>>n;
    int need=1;
    int ret=0;
    for (int i=0;i<2*n;i++)
    {
        string s;
        cin>>s;
        int x=-1;
        if (s[0]=='a')
            cin>>x;
        if (x==-1)
        {
            S.erase(S.find(need));
            if (sorted==sz)
                sz--,sorted--;
            else if (need==st[sz-1])
            {
                sz--;
            }
            else
            {
                ret++;
                sorted=sz;
                sz--,sorted--;
            }
            need++;
        }
        else
        {
            S.insert(x);
            st[sz]=x;
            if (sorted==sz && *S.begin()==x)
                sorted++;
            sz++;
        }
    }
    cout<<ret<<endl;
}