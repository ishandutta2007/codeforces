# include <iostream>
# include <vector>
# include <algorithm>
using namespace std;
int main()
{
    int c1,c2,c3,c4,c5;
    cin>>c1>>c2>>c3>>c4>>c5;
    c1+=c2+c3+c4+c5;
    if (c1%5!=0 || c1==0)
        cout<<-1<<endl;
    else
        cout<<c1/5<<endl;
}