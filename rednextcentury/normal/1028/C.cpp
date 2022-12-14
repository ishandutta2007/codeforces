#include <bits/stdc++.h>
#define MOD 1000000007
#define ll long long
using namespace std ;
pair<int,int> pre1[1000000],suf1[1000000],pre2[1000000],suf2[1000000];
pair<int,int> X[1000000],Y[1000000];
pair<int,int> Intersect(pair<int,int> A,pair<int,int> B)
{
    return {max(A.first,B.first),min(A.second,B.second)};
}
int main ()
{
    ios::sync_with_stdio(0) ;
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    for (int i=0;i<n;i++)
    {
        cin>>X[i].first>>Y[i].first>>X[i].second>>Y[i].second;
    }
    pre1[0]=X[0];
    pre2[0]=Y[0];
    suf1[n-1]=X[n-1];
    suf2[n-1]=Y[n-1];
    for (int i=1;i<n;i++)
    {
        pre1[i]=Intersect(X[i],pre1[i-1]);
        pre2[i]=Intersect(Y[i],pre2[i-1]);
    }
    for (int i=n-2;i>=0;i--)
    {
        suf1[i]=Intersect(X[i],suf1[i+1]);
        suf2[i]=Intersect(Y[i],suf2[i+1]);
    }
    for (int i=0;i<n;i++)
    {
        pair<int,int> L1 = {-1e9,1e9};
        pair<int,int> R1 = {-1e9,1e9};
        pair<int,int> L2=L1,R2=R1;
        if (i>0)L1=pre1[i-1],L2=pre2[i-1];
        if (i+1<n)R1=suf1[i+1],R2=suf2[i+1];
        pair<int,int> L = Intersect(L1,R1);
        pair<int,int> R = Intersect(L2,R2);
        if (L.first<=L.second && R.first<=R.second)
        {
            cout<<L.first<<' '<<R.first<<endl;
            return 0;
        }
    }
}