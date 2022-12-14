# include <iostream>
# include <string>
# include <vector>
# include <stdio.h>
# include <map>
using namespace std;
int tim[1000000];
int main()
{
    string s;
    cin>>s;
    int n=s.length();
    int num=0;
    for (int i=0;i<n;i++)
    {
        if (s[i]=='F')
        {
            tim[i-num]=num;
            if (i>num && num!=0)
                tim[i-num]=max(tim[i-num],tim[i-num-1]+1);
        }
        else
            num++;
    }
    cout<<tim[n-1-num]<<endl;
}