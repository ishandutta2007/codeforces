#include <iostream>
using namespace std;
int main()
{
    int t, s, x;
    cin>>t>>s>>x;
    if(x>=t&&x!=(t+1)&&((x%s)==(t%s)||(x%s)==((t+1)%s)))
    {
        cout<<"YES"<<endl;
    }
    else
    {
        cout<<"NO"<<endl;
    }
}