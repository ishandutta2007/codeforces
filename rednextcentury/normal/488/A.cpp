#include<bits/stdc++.h>
using namespace std;
bool check(int x)
{
    x=abs(x);
    while(x!=0)
    {
        if (x%10==8)return 1;
        x/=10;
    }
    return 0;
}
int main()
{
    int a;
    cin>>a;
    int b=a+1;
    while(1)
    {
        if (check(b))
            break;
        b++;
    }
    cout<<b-a<<endl;
}