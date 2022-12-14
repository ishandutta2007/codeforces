//#include <cstdlib>
#include<iostream>
#include<cstring>
#include<algorithm>
#include <map>
#include<vector>
using namespace std;
int main()
{
    string s;
    cin>>s;
    s+=",";
    int n=s.length();
    string cur="";
    int num=0;
    string ret1="",ret2="";
    int num2=0;
    for (int i=0;i<n;i++)
    {
        if (s[i]==',' || s[i]==';')
        {

            bool no=0;
            int len=cur.length();
            if (len>1 && cur[0]=='0') no=1;
            for (int j=0;j<len;j++)
            {
                if (cur[j]<'0' || cur[j]>'9')
                    no=1;
            }
            if (len>0 && no==0)
            {
                if (num==0)
                    ret1+=cur;
                else
                    ret1+=","+cur;
                num++;
            }
            else
            {
                if (num2==0)
                ret2+=cur;
                else ret2+="," + cur;
                num2++;
            }
            cur="";
        }
        else
            cur+=s[i];
    }
    if (ret1.length()==0)
        cout<<"-\n";
    else
        cout<<"\""<<ret1<<"\""<<endl;
    if (num2==0)
        cout<<"-\n";
    else
        cout<<"\""<<ret2<<"\""<<endl;
}