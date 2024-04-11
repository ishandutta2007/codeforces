# include <iostream>
# include <stdio.h>
# include <algorithm>
# include <set>
using namespace std;
int a[100001];
multiset<int> s;
int st[100001];
int en[100001];
int tot=0,ans=0;
int main()
{
    int n,k;
    cin>>n>>k;
    for (int i=0;i<n;i++)
        cin>>a[i];
    int l=0,r=0;
    bool p=1;
    while(1)
    {
        if (p)
            s.insert(a[r]);
        p=0;
        multiset<int>::iterator it=s.begin();
        int mn=*it;
        it=s.end();
        it--;
        int mx=*it;
        if (mx-mn<=k)
        {
            if (r-l+1>ans)
            {
                ans=r-l+1;
                st[0]=l,en[0]=r,tot=1;
            }
            else if (r-l+1==ans)
                st[tot]=l,en[tot++]=r;
            r++;p=1;
        }
        else
            s.erase(s.find(a[l])),l++;
        if (r==n)
            break;
    }
    cout<<ans<<" "<<tot<<endl;
    for (int i=0;i<tot;i++)
    {
        cout<<st[i]+1<<" "<<en[i]+1<<endl;
    }
}