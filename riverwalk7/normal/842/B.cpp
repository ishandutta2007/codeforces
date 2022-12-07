#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;
int a, b, r;
int x, y;
int ans;
int main()
{
    int R, d;
    int N;
    cin>>R>>d>>N;
    x = R-d; y = R;
    for(int i=0; i<N; i++)
    {
        cin>>a>>b>>r;
        if(((x+r)*(x+r)) <= (a*a+b*b) && (a*a+b*b) <= ((y-r)*(y-r)))
        {
            if((y-r) >= 0)
            {
                ans++;
            }
        }
    }
    cout<<ans<<endl;
}