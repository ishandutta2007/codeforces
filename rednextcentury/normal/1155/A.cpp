#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    int n;
    string s;
    cin>>n>>s;
    char mx = 'a';
    int id = -1;
    for (int i=0;i<n;i++)
    {
        if (s[i]>mx)
        {
            mx = s[i];
            id = i;
        }
        if (s[i]<mx)
        {
            cout<<"YES\n";
            cout<<id+1<<' '<<i+1<<endl;
            return 0;
        }
    }
    cout<<"NO"<<endl;
}