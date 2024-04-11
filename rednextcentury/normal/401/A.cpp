# include <iostream>
# include <string>
# include <cstring>
# include <cstdlib>
# include <algorithm>
# include <cmath>
# include <iomanip>
# include <queue>
# include <map>
# include <vector>
# include <stack>
using namespace std;
int main()
{
    int n,x;
    cin>>n>>x;
    int sum=0;
    for (int i=0;i<n;i++)
    {
        int y;
        cin>>y;
        sum+=y;
    }
    if (abs(sum)%x==0)
    cout<<abs(sum)/x<<endl;
    else
    cout<<abs(sum)/x+1<<endl;
}