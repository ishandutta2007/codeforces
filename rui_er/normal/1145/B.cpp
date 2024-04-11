#include <iostream>
using namespace std;

const bool table[]={1,0,1,1,1,1,1,0,1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,1,1,1,1,0,1,0,1,0,1,1,1,1,1,0,1,0,1,0,1,1,1,1,1,0,1,0,1,0,1,1,1,1,1,0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,1,1,1,1,1,0,1,0,0,0,0,0,0,0,0,0,0,0};

const bool _myGet(int n)
{
    return table[n];
}

int main()
{ 
   int n;
   cin>>n;
   cout<<(_myGet(n)?"YES":"NO")<<endl;
   return 0;
}