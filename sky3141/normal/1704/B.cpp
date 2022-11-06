#include <iostream>
#define MAX 200005
#define LL long long
using namespace std;
LL int a[MAX];

int main()
{
    LL int t;
    cin>>t;
    for(int _case = 0; _case < t; ++_case)
    {
        LL int n,x;
        cin>>n>>x;
        for(int i = 0; i < n; ++i)
        {
            cin>>a[i];
        }
        LL int min = a[0], max = a[0], res = 0;
        for(int i = 1; i < n; ++i)
        {
            min = a[i] < min ? a[i]:min;
            max = a[i] > max ? a[i]:max;
            if(abs(min-max) > 2*x)
            {
                res += 1;
                min = a[i];
                max = a[i];
            }
            //cout<<"\t"<<res<<" "<<min<<" "<<max<<" "<<endl;
        }
        cout<<res<<endl;
    }
}