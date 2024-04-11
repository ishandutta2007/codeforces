#include <iostream>
using namespace std;
typedef long long ll;
ll a1, a2, b1, b2, c1, c2;
int main()
{
    cin>>a1>>a2>>b1>>b2>>c1>>c2;
    if(((a1-b1)*(a1-b1)+(a2-b2)*(a2-b2))==((b1-c1)*(b1-c1)+(b2-c2)*(b2-c2)))
    {
        if((b1-a1)*(c2-b2)==(b2-a2)*(c1-b1))
        {
            cout<<"No"<<endl;
        }
        else
        {
            cout<<"Yes"<<endl;
        }
    }
    else
    {
        cout<<"No"<<endl;
    }
}