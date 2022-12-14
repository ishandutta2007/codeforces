
# include <iostream>
# include <string>
# include <map>
#define EPS 1e-9
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;
    while(m>=n*(n+1)/2)
        m-=n*(n+1)/2;
    for (int i=n-1;i>=0;i--)
    {
        if (m>=(i*(i+1)/2))
        {
            cout<<m-i*(i+1)/2<<endl;
            return 0;
        }
    }
}