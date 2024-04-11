#include<iostream>

using namespace std;

#define MAXN 200001

int a[MAXN];
bool b[MAXN];


int main ()
{
    string s1,s2;
    int n,i;

    cin>>s1>>s2;

    n=s1.size();

    for(i=1;i<=n;i++)
        cin>>a[i];


    int l,r,mid,pr=0,j;

    l=0;
    r=n;

    while(l!=r)
    {
        //cout<<l<<" "<<r<<endl;

        mid=(l+r+1)/2;

        for(i=0;i<=n;i++)
            b[i]=1;

        for(i=1;i<=mid;i++)
            b[a[i]-1]=0;

        j=0;

        for(i=0;i<n && j<s2.size();i++)
        {
            //cout<<b[i]<<endl;
            if(b[i])
            {
                if(s1[i]==s2[j])j++;
            }
        }

        if(j==s2.size())
            l=mid;
        else
            r=mid-1;
    }

    cout<<l<<endl;

    return 0;
}