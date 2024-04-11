#include<bits/stdc++.h>
using namespace std;
map<string,bool> mymap;
string a;
int n;
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        cin>>a;
        map<string,bool>::iterator it=mymap.find(a);
        if(it==mymap.end()) printf("NO\n"),mymap[a]=true;
        else printf("YES\n");
    }
    return 0;
}