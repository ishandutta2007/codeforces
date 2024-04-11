#include<bits/stdc++.h>
using namespace std;
int p[1000000];
int notleaf[1000000];
int num[1000000];
int main()
{
    int n;
    cin>>n;
    for (int i=2;i<=n;i++)
    {
        cin>>p[i];
        notleaf[p[i]]=true;
    }
    for (int i=2;i<=n;i++)
    {
        if (notleaf[i]==false)
            num[p[i]]++;
    }
    for (int i=1;i<=n;i++)
    {
        if (notleaf[i] && num[i]<3){
            cout<<"No"<<endl;
            return 0;
        }
    }
    cout<<"Yes"<<endl;
}