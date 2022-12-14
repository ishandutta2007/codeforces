#include <iostream>
using namespace std;
int main()
{
    int n,h;
    cin>>n>>h;
    int ans=n;
    for (int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        if (x>h)
            ans++;
    }
    cout<<ans<<endl;
}