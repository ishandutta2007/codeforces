# include <algorithm>
# include <iostream>
using namespace std;
int a[3];
int main ()
{
    string s;
    cin>>s;
    for (int i=0;i<s.size();i++)
    {
        if (i%2)continue;
        a[s[i]-'1']++;
    }
    for (int i=0;i<3;i++)
        if (a[i]){a[i]--,cout<<i+1;break;}
    for (int i=0;i<3;i++)
        while(a[i]--)
            cout<<"+"<<i+1;
    cout<<endl;
}