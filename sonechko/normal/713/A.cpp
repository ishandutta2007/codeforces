#include<bits/stdc++.h>
using namespace std;
#define pb push_back
const int N = 1e6 + 11;
///-------------------------------------------------------
int a[N];
///-------------------------------------------------------
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    for (int i=1; i<=n; i++)
    {
        char ch;
        cin>>ch;
        string s;
        cin>>s;
        int sum1=0,step=1;
        for (int i=s.size(); i>=0; i--)
        {
            if (s[i]=='1'||s[i]=='3'||s[i]=='5'||s[i]=='7'||s[i]=='9')
                sum1+=step;
            step*=2;
        }
        if (ch=='+') a[sum1]++; else
        if (ch=='-') a[sum1]--; else cout<<a[sum1]<<endl;
    }
}