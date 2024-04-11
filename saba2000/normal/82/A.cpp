#include <iostream>
using namespace std;
int main ()
{int n,p=5,i;
cin>>n;
while (n>p)
	{n-=p;
	p*=2;
	}
i=(n-1)/(p/5)+1;
switch (i)
{case 1:{cout<<"Sheldon"<<endl; break;}
 case 2:{cout<<"Leonard"<<endl; break;}
 case 3:{cout<<"Penny"<<endl; break;}
 case 4:{cout<<"Rajesh"<<endl; break;}
 default:{cout<<"Howard"<<endl;}
}
//system ("pause");
return 0;
}