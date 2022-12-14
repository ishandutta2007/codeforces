#include <bits/stdc++.h>
using namespace std;
int a[1000000];
int b[1000000];
bool is[1000000];
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    string s;
    int n;
    cin>>n;
    for (int i=0;i<n;i++)
        cin>>a[i];
    for (int i=0;i<n;i++)
        cin>>b[i];
    int cur=0;
    for (int i=0;i<n;i++)
    {
        int num=0;
        while(!is[b[i]])
        {
            is[a[cur]]=1;
            cur++;
            num++;
        }
        cout<<num<<' ';
    }
    cout<<endl;
}