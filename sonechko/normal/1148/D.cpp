#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define ll long long

const int N = 5e5 + 11;

struct ccc
{
    int x,y,num;
};

ccc a[N],b[N];

bool cmp1(ccc a, ccc b)
{
    return a.y>b.y;
}

bool cmp2(ccc a, ccc b)
{
    return a.x<b.x;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    int m1=0,m2=0;
    for (int i=1; i<=n; i++)
    {
        int l,r;
        cin>>l>>r;
        if (l<r)
        {
            m1++;
            a[m1].x=l;
            a[m1].y=r;
            a[m1].num=i;
        } else
        {
            m2++;
            b[m2].x=l;
            b[m2].y=r;
            b[m2].num=i;
        }
    }
    if (m1>m2)
    {
        sort(a+1,a+m1+1,cmp1);
        cout<<m1<<endl;
        for (int i=1; i<=m1; i++)
            cout<<a[i].num<<" ";
        cout<<endl;
    } else
    {
        sort(b+1,b+m2+1,cmp2);
        cout<<m2<<endl;
        for (int i=1; i<=m2; i++)
            cout<<b[i].num<<" ";
        cout<<endl;
    }
}
/**
3 2  5 4 6 1
**/