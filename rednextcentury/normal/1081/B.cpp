#include <bits/stdc++.h>
using namespace std;
vector<int> vec[1000000];
vector<int> num[1000000];
int ret[1000000];
int a[1000000];
int p=0;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    for (int i=1;i<=n;i++)
        cin>>a[i],num[a[i]].push_back(i);
    for (int i=0;i<n;i++)
    {
        int need = n-i;
        int have = num[i].size();
        if (have%need)
        {
            cout<<"Impossible"<<endl;
            return 0;
        }
        for (int j=0;j<have;j++)
        {
            if (j%need==0)p++;
            ret[num[i][j]]=p;
        }
    }
    cout<<"Possible"<<endl;
    for (int i=1;i<=n;i++)
        cout<<ret[i]<<' ';
    cout<<endl;
}