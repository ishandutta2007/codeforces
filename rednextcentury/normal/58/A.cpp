


# include <iostream>
# include <string>
# include <algorithm>
using namespace std;
int main()
{
    string s="hello";
    int m=5;
    int n;
    string a;
    cin>>a;
    n=a.length();
    int now=0;
    for (int i=0;i<n;i++)
    {
        if (s[now]==a[i])
            now++;
        if (now==m)
        {
            cout<<"YES"<<endl;
            return 0;
        }
    }
    cout<<"NO"<<endl;
}