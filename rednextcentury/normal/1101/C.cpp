#include <bits/stdc++.h>

using namespace std;
struct range
{
    int l,r;
    int id;
};
bool operator<(range a,range b)
{
    if (a.l==b.l)return a.r>b.r;
    return a.l<b.l;

}
range a[1000000];
int ret[1000000];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        multiset<int> s;
        for (int i=0;i<n;i++)
            cin>>a[i].l>>a[i].r,a[i].id=i;
        sort(a,a+n);
        int num=n;
        int l=0;
        int mx=0;
        bool ok=0;
        for (int i=0;i<n;i++)
        {
            mx=max(mx,a[i].r);
            while(l<n && a[l].l<=mx)
            {
                mx=max(mx,a[l].r);
                num--;
                l++;
            }
            if (num>0 && l<n)
            {
                for (int j=0;j<l;j++)
                    ret[a[j].id]=1;
                for (int j=l;j<n;j++)
                    ret[a[j].id]=2;
                ok=1;
                break;
            }
        }
        if (!ok)cout<<-1<<endl;
        else
        {
            for (int i=0;i<n;i++)
                cout<<ret[i]<<' ';
            cout<<endl;
        }
    }
}