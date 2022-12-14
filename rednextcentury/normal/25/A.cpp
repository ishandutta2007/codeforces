# include <iostream>
# include <algorithm>
using namespace std;
int main()
{
    int o=0,e=0;
    int l_o,l_e;
    int n;
    cin>>n;
    for (int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        if (x%2)
            o++,l_o=i+1;
        else
            e++,l_e=i+1;
    }
    cout<< (o>e?l_e:l_o) <<endl;
}