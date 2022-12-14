#include <bits/stdc++.h>
#define MOD 1000000007
#define ll long long
using namespace std ;
int main ()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    int n;
    cin>>n;
    string s;
    cin>>s;
    int a=0,b=0;
    for (int i=0;i<n;i++)
    {
        if (s[i]=='8')a++;
        else b++;
    }
    int best=0;
    for (int i=1;i<=a;i++)
    {
        int B = b+a-i;
        if (B>=i*10)
            best=i;
    }
    cout<<best<<endl;

}