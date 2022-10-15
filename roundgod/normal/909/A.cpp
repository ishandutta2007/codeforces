#include<bits/stdc++.h>
#define MAXN 100005
using namespace std;
vector<string> str;
string x,y;
int main()
{
    cin>>x>>y;
    int a=x.size(),b=y.size();
    for(int i=0;i<a;i++)
        for(int j=0;j<b;j++)
        {
            string cat=x.substr(0,i+1)+y.substr(0,j+1);
            str.push_back(cat);
        }
    sort(str.begin(),str.end());
    cout<<str[0]<<endl;
    return 0;
}