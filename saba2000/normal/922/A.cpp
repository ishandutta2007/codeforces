#include<bits/stdc++.h>
using namespace std;

main()
{int x,y;
cin >> y>> x;
if(x>=1 && y>=(x-1) && y%2==(x-1)%2 && (y==0  || x!=1)) cout<<"Yes"<<endl;
else cout<<"No"<<endl;
}