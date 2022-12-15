#include<iostream>
#include<algorithm>

using namespace std;

struct duo
{
    int v,num;
};

int a[200000];
duo b[200000];
int res[200000];

bool cmp(duo t1,duo t2)
{
    return t1.v>t2.v;
}

int main ()
{
    int m,i;

    cin>>m;

    for(i=0;i<m;i++)cin>>a[i];
    for(i=0;i<m;i++)
    {
        cin>>b[i].v;
        b[i].num=i;
    }

    sort(a,a+m);
    sort(b,b+m,cmp);

    for(i=0;i<m;i++)
    {
        //cout<<b[i].num<<endl;
        res[b[i].num]=a[i];
    }

    for(i=0;i<m-1;i++)cout<<res[i]<<" ";
    cout<<res[i]<<endl;

    return 0;
}