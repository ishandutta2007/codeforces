#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a,b,c;
    cin>>a>>b>>c;
    for (int i=a;i>=0;i--)
    {
        int x=2*i;
        int y=4*i;
        if (b>=x && c>=y)
        {
            cout<<7*i<<endl;
            return 0;
        }
    }
}