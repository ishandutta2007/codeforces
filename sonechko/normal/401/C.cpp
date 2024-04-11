#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,m;
    cin>>n>>m;
    string s="";
    while (n>0||m>0)
    {
        if (n>m/2&&(s.size()==0||s[s.size()-1]=='1')) {n--; s+="0";} else
        if (m>0&&(s.size()<=1||s[s.size()-1]=='0'||s[s.size()-2]=='0')) {m--; s+="1";} else
        if (s.size()!=0&&s[s.size()-1]=='0'&&m==0) {cout<<-1<<endl; return 0;} else
        if (n==0) {cout<<-1<<endl; return 0;} else
        {
                n--;
                s+="0";
        }
    }
    cout<<s<<endl;
}