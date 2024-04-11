#include <bits/stdc++.h>
#define MOD 1000000007
#define ll long long
using namespace std;

    int a=3,b=1;
int query(int c,int d)
{
    cout<<"? "<<c<<' '<<d<<endl;

    fflush(stdout);
    int x;
    cin>>x;
    return x;

}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int c=0,d=0;
    int cur = query(c,d);
    for (int i=29;i>=0;i--)
    {
        int op = query(c+(1<<i),d+(1<<i));
        if (cur==op)
        {
            if (cur==-1)
            {
                int x = query(c,d+(1<<i));
                if (x==1)
                {
                    c+=(1<<i);
                    d+=(1<<i);
                }
            }
            else
            {
                int x = query(c+(1<<i),d);
                if (x==-1)
                {
                    c+=(1<<i);
                    d+=(1<<i);
                }
            }
        }
        else
        {
            if (cur==-1)
                d+=(1<<i);
            else
                c+=(1<<i);
            cur = query(c,d);
        }
    }
    cout<<"! "<<c<<' '<<d<<endl;
}