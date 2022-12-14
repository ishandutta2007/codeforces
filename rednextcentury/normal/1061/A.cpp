#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,s;
    cin>>n>>s;
    int ret=0;
    for (int i=n;i>=1;i--)
    {
        if (s>=i)
        {
            long long num=s/i;
            s-=num*i;
            ret+=num;
        }
    }
    cout<<ret<<endl;
}