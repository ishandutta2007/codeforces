#include <iostream>
# include <map>
# include <string>
using namespace std;
map <long long,long long> a;
map <long long,long long> b;
int main()
{
    long long n,m,s,f;
    cin>>n>>m>>s>>f;
    for (long long i=0;i<m;i++)
    {
        long long time,start,end;
        cin>>time>>start>>end;
        a[time]=start;
        b[time]=end;
    }
    string steps;
    long long t=1;
    while (s!=f)
    {
        if (s>f)
        {
            if ((s-1<a[t] || s-1>b[t]) && (s<a[t] || s>b[t]))
            {
                steps+="L";
                s--;
            }
            else
                steps+="X";
        }
        else
        {
            if ((s+1<a[t] || s+1>b[t]) && (s<a[t] || s>b[t]))
            {
                steps+="R";
                s++;
            }
            else
                steps+="X";
        }
        t++;
    }
    cout<<steps<<endl;
}