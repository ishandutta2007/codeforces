#include<bits/stdc++.h>
using namespace std;
long long x[1000000];
int id[1000000];
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    long long ret=0;
    bool hasP=0;
    for (int i=0;i<n;i++)
    {
        char typ;
        cin>>x[i]>>typ;
        if (typ=='B')id[i]=0;
        if (typ=='R')id[i]=1;
        if (typ=='P')id[i]=2,hasP=1;
    }
    int l;
    long long mn0=2e9;
    long long mn1=2e9;
    for (l=0;l<n;l++)
    {
        if (id[l]==0)mn0=min(mn0,x[l]);
        if (id[l]==1)mn1=min(mn1,x[l]);
        if (id[l]==2)
        {
            if (mn0!=2e9)ret+=x[l]-mn0;
            if (mn1!=2e9)ret+=x[l]-mn1;
            break;
        }
    }
    int r;
    long long mx0=-2e9;
    long long mx1=-2e9;
    for (r=n-1;r>=0;r--)
    {
        if (id[r]==0)mx0=max(mx0,x[r]);
        if (id[r]==1)mx1=max(mx1,x[r]);
        if (id[r]==2)
        {
            if (mx0!=-2e9)ret+=mx0-x[r];
            if (mx1!=-2e9)ret+=mx1-x[r];
            break;
        }
    }
    if (!hasP)
    {
        if (mx0!=-2e9)ret+=mx0-mn0;
        if (mx1!=-2e9)ret+=mx1-mn1;
        cout<<ret<<endl;
        return 0;
    }
    int last=l;
    vector<long long> R;
    vector<long long> B;
    for (int i=l+1;i<=r;i++)
    {
        if (id[i]==2)
        {
            long long curR = 0;
            if (R.size())
            {
                curR = min(x[i]-R[0],R[R.size()-1]-x[last]);
                for (int j=0;j+1<R.size();j++)
                    curR = min(curR, R[j]-x[last]+x[i]-R[j+1]);
            }
            long long curB = 0;
            if (B.size())
            {
                curB = min(x[i]-B[0],B[B.size()-1]-x[last]);
                for (int j=0;j+1<B.size();j++)
                    curB = min(curB, B[j]-x[last]+x[i]-B[j+1]);
            }
            ret+=min(curR+curB+x[i]-x[last],(x[i]-x[last])*2);
            R.clear();
            B.clear();
            last=i;
        }
        else if (id[i]==0)R.push_back(x[i]);
        else B.push_back(x[i]);
    }
    cout<<ret<<endl;
}