# include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string a,b;
    cin>>a>>b;
    int n;
    cin>>n;
    cout<<a<<' '<<b<<endl;
    while(n--)
    {
        string x,y;
        cin>>x>>y;;
        if (x==a)
            a=y;
        else b=y;
        cout<<a<<' '<<b<<endl;
    }
}