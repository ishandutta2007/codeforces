#include <iostream>
#include <fstream>
using namespace std;
typedef long long ll;
int T, N; ll B, x, y; ll sum, cur;
int main()
{
    cin>>T;
    for(int i=0; i<T; i++)
    {
        cin>>N>>B>>x>>y;
        sum = cur = 0;
        for(int j=0; j<N; j++)
        {
            if(cur + x <= B)
            {
                cur += x;
            }
            else
            {
                cur -= y;
            }
            sum += cur;
        }
        cout<<sum<<endl;
    }
}