# include <iostream>
# include <string>
# include <algorithm>
using namespace std;
string a[1000];
int main()
{
    string s;
    cin>>s;
    int n=s.length();
    int m;
    cin>>m;
    int tot=0;
    a[0]=s;
    for (int i=0;i<m;i++)
    {
        string x;
        cin>>x;
        if (x.length()<n)
            continue;
        if (x.substr(0,n)==s)
            a[tot++]=x;
    }
    sort(a,a+tot);
    cout<<a[0]<<endl;
}