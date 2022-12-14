#include<bits/stdc++.h>
using namespace std;
int a[1000000];
queue<int> odd;
queue<int> even;
map<int,int> mp;
int main()
{
    int n,m;
    cin>>n>>m;
    int e=0,o=0;
    for (int i=0;i<n;i++)
    {
        cin>>a[i];
        mp[a[i]]++;
        if (a[i]%2)o++;
        else e++;
    }
    m=min(m,1000000);
    for (int i=1;i<=m;i++)
    {
        if (mp.count(i)==0)
        {
            if (i%2)odd.push(i);
            else even.push(i);
        }
    }
    int cost=0;
    for (int i=0;i<n;i++)
    {
        if (mp[a[i]]>1)
        {
            mp[a[i]]--;
            if (a[i]%2)
            {
                if (o>e)
                {
                    if (even.empty())
                    {
                        cout<<"-1\n";
                        return 0;
                    }
                    a[i]=even.front();
                    even.pop();
                    cost++;
                    o--;
                    e++;
                }
                else
                {
                    if (odd.empty())
                    {
                        cout<<"-1\n";
                        return 0;
                    }
                    a[i]=odd.front();
                    odd.pop();
                    cost++;
                }
            }
            else
            {
                if (e>o)
                {
                    if (odd.empty())
                    {
                        cout<<"-1\n";
                        return 0;
                    }
                    a[i]=odd.front();
                    odd.pop();
                    cost++;
                    e--;
                    o++;
                }
                else
                {
                    if (even.empty())
                    {
                        cout<<"-1\n";
                        return 0;
                    }
                    cost++;
                    a[i]=even.front();
                    even.pop();
                }
            }
        }
    }
    for (int i=0;i<n;i++)
    {
        if (a[i]%2)
        {
            if (o>e)
            {
                if (even.empty())
                {
                    cout<<"-1\n";
                    return 0;
                }
                a[i]=even.front();
                even.pop();
                cost++;
                o--;
                e++;
            }
        }
        else
        {
            if (e>o)
            {
                if (odd.empty())
                {
                    cout<<"-1\n";
                    return 0;
                }
                a[i]=odd.front();
                odd.pop();
                cost++;
                e--;
                o++;
            }

        }
    }
    cout<<cost<<endl;
    for (int i=0;i<n;i++)
        cout<<a[i]<<' ';
}