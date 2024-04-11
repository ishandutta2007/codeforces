#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
int ff(string s)
{
    if((int)s.length()>=4&&s.substr((int)s.length()-4,4)=="lios")return 0;
    if((int)s.length()>=5&&s.substr((int)s.length()-5,5)=="liala")return 1;
    if((int)s.length()>=3&&s.substr((int)s.length()-3,3)=="etr")return 2;
    if((int)s.length()>=4&&s.substr((int)s.length()-4,4)=="etra")return 3;
    if((int)s.length()>=6&&s.substr((int)s.length()-6,6)=="initis")return 4;
    if((int)s.length()>=6&&s.substr((int)s.length()-6,6)=="inites")return 5;
    return -1;
}
int main()
{
    vector<int> a;
    string s;
    while(cin>>s)a.push_back(ff(s));
    for(int i=0;i<(int)a.size();i++)
        if(a[i]==-1){puts("NO");return 0;}
    if((int)a.size()==1){puts("YES");return 0;}
    bool F0=0,F1=0;
    for(int i=0;i<(int)a.size();i++)
        if(a[i]&1)F1=1;else F0=1;
    if(F0&&F1){puts("NO");return 0;}
    int p=-1;
    for(int i=0;i<(int)a.size();i++)
        if(a[i]/2==1)if(p==-1)p=i;else {puts("NO");return 0;}
    if(p==-1){puts("NO");return 0;}
    for(int i=0;i<p;i++)
        if(a[i]/2!=0){puts("NO");return 0;}
    for(int i=p+1;i<(int)a.size();i++)
        if(a[i]/2!=2){puts("NO");return 0;}
    puts("YES");
    return 0;
}