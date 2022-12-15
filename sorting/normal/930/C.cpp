#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int a[100005];
int one[100005],two[100005];
int n,m;

vector<int> d;

int res()
{
    int ans=0,i;

    d.resize(0);
    for(i=1;i<=m;i++)
    {
        if(upper_bound(d.begin(), d.end(), a[i]) ==d.end())
        {
            d.push_back(a[i]);
        }
        else *upper_bound(d.begin(), d.end(), a[i])=a[i];
        one[i]=d.size();
        //cout<<one[i]<<endl;
    }
    d.resize(0);
    for(i=m;i>=1;i--)
    {
        if(upper_bound(d.begin(), d.end(), a[i]) ==d.end())
        {
            d.push_back(a[i]);
        }
        else *upper_bound(d.begin(), d.end(), a[i])=a[i];
        two[i]=d.size();
    }

    for(i=2;i<=m;i++)
    {
        ans=max(ans,one[i-1]+two[i]);
    }
    for(i=1;i<m;i++)
    {
        ans=max(ans,one[i]+two[i+1]);
    }
    ans=max(ans,two[1]);
    ans=max(ans,one[m]);

    return ans;
}

int main ()
{
    int i,l,r,maxi=0;
    bool b;

    cin>>n>>m;

    for(i=0;i<n;i++)
    {
        cin>>l>>r;
        a[l]+=1;
        a[r+1]+=-1;
    }

    l=0;

    for(i=1;i<=m;i++)
    {
        l+=a[i];
        a[i]=l;

        //cout<<a[i]<<" a[i"<<endl;
    }

    cout<<res()<<endl;

    return 0;
}