#include <iostream>
#include <fstream>
using namespace std;
typedef long long ll;
int T; ll a, b;
bool flag;
int main()
{
    cin>>T;
    for(int i=0; i<T; i++)
    {
        cin>>a>>b;
        if(a-b > 1)
        {
            cout<<"NO"<<endl;
        }
        else
        {
            flag = true;
            for(ll j = 2; j < min(a+b-1, 1000000LL); j++)
            {
                if((a+b)%j==0)
                {
                    cout<<"NO"<<endl;
                    flag = false;
                    break;
                }
            }
            if(flag)
            {
                cout<<"YES"<<endl;
            }
        }
    }
}