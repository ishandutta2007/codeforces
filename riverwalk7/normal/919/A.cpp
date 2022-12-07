#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;
int n, m;
double a, b;
double ans = 1e26;
int main()
{
    cin>>n>>m;
    for(int i=0; i<n; i++)
    {
        cin>>a>>b;
        ans = min(ans, (double)(m)*a/b);
    }
    cout<<fixed<<setprecision(6);
    cout<<ans<<endl;
}