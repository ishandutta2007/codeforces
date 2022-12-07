#include <iostream>
#include <fstream>
using namespace std;
typedef long long ll;
ll fence_type[4]; //fence_type[2*i+j], 0 <= i, j <= 1 counts the number of fences that are on a coordinate that is 2*i mod 4 and 2*j mod 4
int N;
int x, y;
ll ans;
ll count_fences(int type_a, int type_b, int type_c)
{
    if(type_a == type_b && type_b == type_c)
    {
        return fence_type[type_a]*(fence_type[type_b]-1)*(fence_type[type_c]-2)/6;
    }
    else if(type_a == type_b)
    {
        return fence_type[type_a]*(fence_type[type_b]-1)/2*fence_type[type_c];
    }
    else if(type_b == type_c)
    {
        return fence_type[type_a]*fence_type[type_b]*(fence_type[type_c]-1)/2;
    }
    else
    {
        //if all 3 fence types are different then it doesn't work so we don't count it
        return 0;
    }
}
int main()
{
    cin>>N;
    for(int i=0; i<N; i++)
    {
        cin>>x>>y;
        fence_type[(x%4)+(y%4)/2]++;
    }
    for(int i=0; i<4; i++)
    {
        for(int j=i; j<4; j++)
        {
            for(int k=j; k<4; k++)
            {
                ans += count_fences(i, j, k);
            }
        }
    }
    cout<<ans<<endl;
}