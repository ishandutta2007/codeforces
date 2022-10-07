#include<bits/stdc++.h>
using namespace std;
int M[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
main()
{int m,d;
cin>>m>>d;
cout<<(M[m]-(8-d)+6)/7+1<<endl;
}