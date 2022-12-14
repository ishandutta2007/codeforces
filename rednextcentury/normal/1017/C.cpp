#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int mn=1e9;
    int best=-1;
    for (int i=1;i<=n;i++)
    {
        int L = i;
        int R = n/i+(n%i>0);
        if (L+R<mn)
        {
            mn=L+R;
            best = i;
        }
    }
    int num = n/best+(n%best>0);
    int cur=n;
    for (int i=1;i<=num;i++)
    {
        for (int j=max(1,cur-best+1);j<=cur;j++)
            cout<<j<<' ';
        cur = cur-best;
    }
    cout<<endl;
}