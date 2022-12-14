
# include <iostream>
# include <string>
# include <map>
#define EPS 1e-9
using namespace std;
int main()
{
    int r,g,b;
    cin>>r>>g>>b;
    r=r/2 + r%2;
    g=g/2 + g%2;
    b=b/2 + b%2;
    cout<< max(3*(r-1),max(3*(g-1)+1,3*(b-1)+2))+30<<endl;;
}