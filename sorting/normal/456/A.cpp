#include<iostream>
#include<algorithm>
#define endl "\n"

using namespace std;

struct duo
{
    int a,b;
};

bool cmp (duo x,duo y)
{
    if(x.a<y.a)return 1;
    if(x.a>y.a)return 0;
    return 0;
}

duo d[100001];

int main ()
{
    int n,i;

    ios::sync_with_stdio(false);

    cin>>n;

    for(i=0;i<n;i++)
    {
        cin>>d[i].a>>d[i].b;
    }

    sort(d,d+n,cmp);

    for(i=1;i<n;i++)
    {
        if(d[i].b<d[i-1].b)
        {
            cout<<"Happy Alex"<<endl;
            return 0;
        }
    }

    cout<<"Poor Alex"<<endl;
    return 0;
}