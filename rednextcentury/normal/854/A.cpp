# include <bits/stdc++.h>
using namespace std;
int GCD(int a,int b)
{
    if (b==0)return a;
    if (a==0)return b;
    if (a%b==0)return b;
    if (b%a==0)return a;
    return GCD(b,a%b);
}
int main()
{
    int n;
    cin>>n;
    for (int a=n/2;a>=1;a--)
    {
        int b=n-a;
        if (GCD(a,b)==1)
        {
            cout<<a<<' '<<b<<endl;
            return 0;
        }
    }
    cout<<0<<' '<<n<<endl;
}