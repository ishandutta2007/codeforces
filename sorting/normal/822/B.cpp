#include<iostream>

using namespace std;

int main ()
{
    int n,m,i,j,k,res=-1,pos;
    string s,t;

    cin>>n>>m;

    cin>>s>>t;

    for(i=0;i<m-n+1;i++)
    {
        k=0;
        for(j=0;j<n;j++)
        {
            if(s[j]==t[i+j])
                k++;
        }
        if(k>res)
        {
            res=k;
            pos=i;
        }
    }

    cout<<n-res<<endl;

    for(j=0;j<n;j++)
        if(s[j]!=t[pos+j])
            cout<<j+1<<" ";

    return 0;
}