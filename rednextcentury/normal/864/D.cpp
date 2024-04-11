#include<bits/stdc++.h>
using namespace std;
int a[1000000];
int num[1000000];
int is[1000000];
set<int> s;
int main()
{
    int n;
    cin>>n;
    int ret=0;
    for (int i=1;i<=n;i++)
        cin>>a[i],num[a[i]]++;
    for (int i=1;i<=n;i++)if(num[i]==0)s.insert(i);
    for (int i=1;i<=n;i++)
    {
        if (num[a[i]]>1)
        {
            int x=*s.begin();
            if (x<a[i])
                num[a[i]]--,a[i]=x,ret++,s.erase(s.begin());
            else
            {
                if (!is[a[i]])is[a[i]]=1;
                else
                {
                    num[a[i]]--;
                    a[i]=x;
                    ret++;
                    s.erase(s.begin());
                }
            }
        }
    }
    cout<<ret<<endl;
    for (int i=1;i<=n;i++)
        cout<<a[i]<<' ';
    cout<<endl;
}