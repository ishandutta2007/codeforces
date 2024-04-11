#include <bits/stdc++.h>
using namespace std;
int a[5001];
int num[5001][5001];
int ret[5001];
int main()
{
    int n;
    cin>>n;
    for (int i=1;i<=n;i++)
        cin>>a[i];
    for (int i=1;i<=n;i++)
    {
        num[i][a[i]]++;
        int mx=1,id=a[i];
        ret[a[i]]++;
        for (int j=i+1;j<=n;j++)
        {
            num[i][a[j]]++;
            if (num[i][a[j]]>mx)
                mx=num[i][a[j]],id=a[j];
            else if (mx==num[i][a[j]] && a[j]<id)
                id=a[j];
            ret[id]++;
        }
    }
    for (int i=1;i<=n;i++)
        cout<<ret[i]<<' ';
    cout<<endl;
}