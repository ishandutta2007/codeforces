# include <iostream>
# include <string>
using namespace std;

int main()
{
    int n;
    string s;
    cin>>n>>s;
    int i=0,num=0;
    if (n%2)
        cout<<s[0]<<s[1]<<s[2],i=3,num=2;

    for (;i<n;i++)
    {
        if (num==2)
            num=0,cout<<"-";
        cout<<s[i];
        num++;
    }
    cout<<endl;
}