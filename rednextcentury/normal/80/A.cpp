
# include <iostream>
# include <string>
# include <map>
#define EPS 1e-9
using namespace std;
bool prime(int n)
{
    for (int i=2;i<n;i++)
        if (n%i==0)
            return 0;
    return 1;
}
int main()
{
    int n,m;
    cin>>n>>m;
    for (int i=n+1;i<=m;i++)
    {
        if (prime(i) && i<m)
        {
            cout<<"NO"<<endl;
            return 0;
        }
        else if (prime(i))
        {
            cout<<"YES"<<endl;
            return 0;
        }
    }
    cout<<"NO"<<endl;
}