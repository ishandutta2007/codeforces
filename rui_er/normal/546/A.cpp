#include <iostream>
using namespace std;

int main()
{
    int k, n, w;
    cin>>k>>n>>w;
    int ans = ((1 + w) * w / 2) * k;
    ans -= n;
    cout<<max(ans, 0)<<endl;
    return 0;
}