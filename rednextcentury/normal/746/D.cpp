#include<bits/stdc++.h>
using namespace std;
int ret[1000000];
int main()
{
    int n,k,a,b;
    cin>>n>>k>>a>>b;
    char A='G',B='B';
    if (a<b)swap(a,b),swap(A,B);
    if (a==b)
        for (int i=0;i<n/2;i++)
            cout<<"GB";
    else
    {
        for (int i=0;i<b+1;i++)
            ret[i]=1,a--;
        for (int i=0;i<b+1;i++)
        {
            if (k-1>a)
                ret[i]+=a,a=0;
            else
                ret[i]=k,a-=k-1;
        }
        if (a>0)
        {
            cout<<"NO"<<endl;
            return 0;
        }
        for (int i=0;i<b+1;i++)
        {
            for (int j=0;j<ret[i];j++)
                cout<<A;
            if (i<b)
                cout<<B;
        }
        cout<<endl;
    }
}