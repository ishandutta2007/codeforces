# include <iostream>
# include <map>
# include <cmath>
# include <cstdlib>
# include <string>
using namespace std;
int main()
{
    int n,m,a,b;
    cin>>n>>m>>a>>b;
    int ans1=0;
    ans1=((n/m)+1)*b;
    int ans2=(n/m)*b+(n%m)*a;
    int ans3=n*a;
    cout<<min(ans1,min(ans2,ans3))<<endl;
}