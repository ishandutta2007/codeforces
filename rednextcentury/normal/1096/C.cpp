#include <bits/stdc++.h>

using namespace std;
int ans[200];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    for (int i=3;i<=1000;i++)
    {
        int A = (i-2)*180;
        int B = i*(i-2);
        int G = __gcd(A,B);
        A/=G;
        B/=G;
        int num = i-2;
        for (int j=1;j<=num;j++)
        {
            if (j%B==0)
            {
                int X = A*(j/B);
                if (ans[X]==0)ans[X]=i;
            }
        }
    }
    while(t--)
    {
        int n;
        cin>>n;
        cout<<ans[n]<<endl;
    }
}