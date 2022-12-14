#include<bits/stdc++.h>
using namespace std;
vector<int> a[100001];
int main()
{
    int n,k,x;
    cin>>n>>k>>x;
    a[0]=vector<int>(n);
    for (int i=0;i<n;i++)
        cin>>a[0][i];;
    int i=1;
    sort(a[0].begin(),a[0].end());
    for (;i<=k;i++)
    {
        a[i]=a[i-1];
        for (int j=0;j<n;j+=2)
            a[i][j]^=x;
        sort(a[i].begin(),a[i].end());
        for (int p=0;p<i;p++)
        {
            if (a[i]==a[p])
            {
                int len=(i-p);
                k-=p;
                cout<<a[k%len+p][n-1]<<' '<<a[k%len+p][0]<<endl;
                return 0;
            }
        }
    }
    cout<<a[k][n-1]<<' '<<a[k][0]<<endl;

}