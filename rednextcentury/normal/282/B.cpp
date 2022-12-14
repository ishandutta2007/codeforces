#include <cstdio>
# include <iostream>
# include <string>
# include <set>
# include <queue>
# include <cstring>
# include <algorithm>
# include <cstdlib>
# include <ios>
using namespace std;
int a[1000001];
int b[1000001];
int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    string s="";
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i] >> b[i];
    int A=0,B=0;
    for (int i=0;i<n;i++)
    {
        if (abs(A+a[i]-B)<abs(B+b[i]-A))
        {
            A+=a[i];
            s+="A";
        }
        else
        {
            B+=b[i];
            s+="G";
        }
    }
    cout<<s<<'\n';
}