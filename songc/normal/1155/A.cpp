#include <bits/stdc++.h>
using namespace std;
string a; int n;
int main()
{
    cin>>n>>a;
    for(int i=0;i<a.size()-1;i++)
    if(a[i]>a[i+1])
    return !printf("YES\n%d %d",i+1,i+2);
    
    printf("NO");
}