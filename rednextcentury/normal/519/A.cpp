# include <iostream>
# include <algorithm>
# include <map>
using namespace std;
char a[10][10];
map<char,int> mp;
int main()
{
    mp['Q']=9;
    mp['R']=5;
    mp['B']=3;
    mp['P']=1;
    mp['N']=3;
    int A=0,B=0;
    for (int i=0;i<8;i++)
    {
        for (int j=0;j<8;j++)
        {
            char x;
            cin>>x;
            if (x=='.')
                continue;
            if ((int)x==tolower(x))
                A+=mp[char(toupper(x))];
            else
                B+=mp[x];

        }
    }
    if (B>A)
        cout<<"White"<<endl;
    else if (A>B)
        cout<<"Black"<<endl;
    else
        cout<<"Draw"<<endl;
}