#include<bits/stdc++.h>
using namespace std;
string s[1000];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string need;
    cin>>need;
    int n;
    cin>>n;
    for (int i=0;i<n;i++)
    {
        cin>>s[i];
    }
    for (int i=0;i<n;i++)
    {
        for (int j=0;j<n;j++)
        {
            string x=s[i]+s[j];
            if (x.find(need)!=x.npos)
            {
                cout<<"YES"<<endl;
                return 0;
            }
        }
    }
    cout<<"NO\n";

}