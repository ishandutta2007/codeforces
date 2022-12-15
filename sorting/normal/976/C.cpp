#include<iostream>
#include<algorithm>

using namespace std;

struct duo
{
    int l,r,before;
};

duo p[300001];

bool cmp(duo a,duo b)
{
    if(a.l<b.l)
        return 1;
    if(a.l>b.l)
        return 0;
    if(a.r>b.r)
        return 1;
    return 0;
}

int main ()
{
    int n,i,maxi,which;

    cin>>n;

    for(i=0;i<n;i++)
    {
        cin>>p[i].l>>p[i].r;
        p[i].before=i;
    }

    sort(p,p+n,cmp);

    maxi=p[0].r;
    which=p[0].before;

    //cout<<p[0].before<<endl;

    //cout<<maxi<<endl;

    for(i=1;i<n;i++)
    {
        //cout<<p[i].before<<endl;
       // cout<<i<<endl;
        if(maxi>=p[i].r)
        {
            cout<<p[i].before+1<<" "<<which+1<<endl;
            return 0;
        }
        if(p[i].r>maxi)
        {
            maxi=p[i].r;
            which=p[i].before;
        }
    }

    cout<<"-1 -1"<<endl;

    return 0;
}