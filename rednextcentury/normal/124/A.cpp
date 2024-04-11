
# include <iostream>
# include <string>
# include <algorithm>
# include <map>
#include<stdio.h>
# include <vector>
#define EPS 1e-9
using namespace std;
int main()
{
    int n,a,b;
    cin>>n>>a>>b;
    int l=max(a,n-b-1);
    cout<<n-l<<endl;
}