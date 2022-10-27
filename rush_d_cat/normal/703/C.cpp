#include <iostream>
#include <set>
using namespace std;
const int NICO = 100000 + 10;
double n, w, v, u, ans;
double x[NICO], y[NICO];
int a = 1, b = 1;
int main()
{
    cin >> n >> w >> v >> u;
    for(int i=1;i<=n;i++)
    {
        cin >> x[i] >> y[i];
        if((x[i]/v)>(y[i]/u)) a = 0;  
        if((x[i]/v)<(y[i]/u)) b = 0;  
        ans=max(ans,x[i]/v+(w-y[i])/u); 
    }
    if(a+b>0)printf("%.10lf\n",w/u);  
    else printf("%.10lf\n",ans);
}