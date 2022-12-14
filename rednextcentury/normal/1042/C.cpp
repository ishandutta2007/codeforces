#include<bits/stdc++.h>
#define ll long long
using namespace std;
long long a[1000000];
vector<int> zero;
void q1(int b,int c)
{
    cout<<1<<' '<<b+1<<' '<<c+1<<endl;
}
void q2(int b)
{
    cout<<2<<' '<<b+1<<endl;
}
int main()
{
    ios_base::sync_with_stdio(0);
    int mxNeg = -1e9;
    int loc=-1;
    int numNeg=0;
    int n;
    cin>>n;
    for (int i=0;i<n;i++)
    {
        cin>>a[i];
        if (a[i]==0)zero.push_back(i);
        if (a[i]<0)
        {
            if (a[i]>=mxNeg)
            {
                mxNeg = a[i];
                loc = i;
            }
            numNeg++;
        }
    }
    if (zero.size()>0)
    {
        if (numNeg%2==0)
        {
            for (int i=1;i<zero.size();i++)
                q1(zero[i-1],zero[i]);
            if (zero.size()!=n)
                q2(zero[zero.size()-1]);
        }
        else
        {
            for (int i=1;i<zero.size();i++)
                q1(zero[i-1],zero[i]);
            q1(loc,zero[zero.size()-1]);
            a[loc]=0;
            if (zero.size()+1<n)
                q2(zero[zero.size()-1]);
        }
    }
    else if (numNeg%2)
    {
        q2(loc);
        a[loc]=0;
    }
    int last=-1;
    for (int i=0;i<n;i++)
    {
        if (a[i]!=0)
        {
            if (last>=0)
            {
                q1(last,i);
            }
            last=i;
        }
    }
}