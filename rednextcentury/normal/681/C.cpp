#include <bits/stdc++.h>
using namespace std;
string ret[2000000];
int a[2000000];
multiset<int> S;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    int tot=0;
    for (int i=0;i<n;i++)
    {
        string s;
        int x;
        cin>>s;
        if (s!="removeMin")
            cin>>x;
        if (s=="insert")
        {
            S.insert(x);
            ret[tot]=s;
            a[tot++]=x;
        }
        else if (s=="removeMin")
        {
            if (S.empty())
            {
                ret[tot]="insert";
                a[tot++]=1;
                ret[tot++]="removeMin";
            }
            else
            {
                S.erase(S.begin());
                ret[tot++]="removeMin";
            }
        }
        else if (s=="getMin")
        {
            while(!S.empty() && *S.begin()<x)
            {
                S.erase(S.begin());
                ret[tot++]="removeMin";
            }
            if (S.empty())
            {
                S.insert(x);
                ret[tot]="insert";
                a[tot++]=x;
                ret[tot]="getMin";
                a[tot++]=x;
            }
            else
            {
                if (*S.begin()!=x)
                {
                    ret[tot]="insert";
                    a[tot++]=x;
                    S.insert(x);
                }
                ret[tot]="getMin";
                a[tot++]=x;
            }
        }
    }
    cout<<tot<<endl;
    for (int i=0;i<tot;i++)
    {
        if (ret[i]=="removeMin")
            cout<<ret[i]<<endl;
        else
            cout<<ret[i]<<' '<<a[i]<<endl;
    }
}