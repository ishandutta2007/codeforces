#include <iostream>
using namespace std;
int N;
char a;
int total[7];
int ans;
int main()
{
    cin>>N;
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<7; j++)
        {
            cin>>a;
            if(a=='1')
            {
                total[j]++;
            }
        }
    }
    for(int k=0; k<7; k++)
    {
        ans = max(ans, total[k]);
    }
    cout<<ans<<endl;
}