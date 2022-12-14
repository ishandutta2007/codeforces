#include<bits/stdc++.h>
#include<cstdio>
using namespace std;

int main()
{
int n;

double x,y,a,b,c=0;
cin>>n>>x>>y;
set<double>s;

for (int i =0 ; i< n ; i++){
    cin>>a>>b;
    if(a-x !=0)s.insert((y-b)/(x-a));
    else c=1;
}
cout<<s.size()+c;
	return 0;
}