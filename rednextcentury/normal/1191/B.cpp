#include <bits/stdc++.h>
using namespace std;
char stupid[] = {'s','p','m'};
bool StupidProblem1(string stupid1,string stupid2,string stupid3)
{
    return stupid1==stupid2 && stupid2==stupid3;
}
bool StupidProblem2(string stupid1,string stupid2,string stupid3)
{
    string stupidStrings[]={stupid1,stupid2,stupid3};
    sort(stupidStrings,stupidStrings+3);
    if (stupidStrings[0][1]==stupidStrings[1][1] && stupidStrings[1][1]==stupidStrings[2][1])
    {
        if (stupidStrings[0][0]+1==stupidStrings[1][0] && stupidStrings[1][0]+1==stupidStrings[2][0])
            return 1;
    }
    return 0;
}

int main()
{
    string a,b,c;
    cin>>a>>b>>c;
    if (StupidProblem1(a,b,c) || StupidProblem2(a,b,c))
        cout<<0<<endl;
    else
    {
        bool ok =0;
        for (char x='1';x<='9';x++)
        {
            for (auto stupidProblemsetter:stupid)
            {
                string s="";s+=x;s+=stupidProblemsetter;
                ok|=StupidProblem1(a,b,s)|StupidProblem1(a,s,c)|StupidProblem1(s,b,c);
                ok|=StupidProblem2(a,b,s)|StupidProblem2(a,s,c)|StupidProblem2(s,b,c);
            }
        }
        if (ok)cout<<1<<endl;
        else cout<<2<<endl;
    }
}