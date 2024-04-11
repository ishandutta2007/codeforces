#include <iostream>
#define MAXN 100
using namespace std;
int x, N;
bool flag;
int main()
{
    cin>>N;
    for(int i=0; i<N; i++)
    {
        cin>>x;
        flag = false;
        for(int j=0; j<=MAXN; j++)
        {
            for(int k=0; k<=MAXN; k++)
            {
                if((3*j+7*k)==x)
                {
                    cout<<"YES"<<endl;
                    flag = true;
                    break;
                }
            }
            if(flag)
            {
                break;
            }
        }
        if(!flag)
        {
            cout<<"NO"<<endl;
        }
    }
}