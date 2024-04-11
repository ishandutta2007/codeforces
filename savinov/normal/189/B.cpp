#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int w,h;
    cin >> w >> h;
    long long ans=0;
    for (int i=0;i<=w;i++)
    {
        for (int j=0;j<=h;j++)
        {
            ans+=((h-j)/2)*min(i,w-i);
        }
    }
    cout << ans << endl;
    return 0;
}