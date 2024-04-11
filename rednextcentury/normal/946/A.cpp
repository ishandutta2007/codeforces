#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int x=0;
    while(n--)
    {
        int y;
        cin>>y;
        x+=abs(y);
    }
    cout<<x<<endl;
}