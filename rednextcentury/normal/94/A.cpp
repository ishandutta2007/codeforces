
# include <iostream>
# include <string>
# include <map>
#define EPS 1e-9
using namespace std;
map<string,int> mp;
int main()
{
    string s;
    cin>>s;
    for (int i=0;i<10;i++)
    {
        string k;
        cin>>k;
        mp[k]=i;
    }
    int x=0;
    while(x<80)
    {
        cout<< mp[ s.substr(x,10) ] ;
        x+=10;
    }
    cout<<endl;
}