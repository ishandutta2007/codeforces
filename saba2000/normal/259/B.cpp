#include <iostream> 
using namespace std;
int main ()
{int a[9]={0},x,y,z,b;
for (int i=0; i<9; i++)
cin>>a[i];
x=a[0]+a[1]+a[2];
y=a[3]+a[4]+a[5];
z=a[6]+a[7]+a[8];
b=a[2]+a[6];
if (x>y && x>z) {a[0]=1; a[4]=x-y+1; a[8]=x-z+1; while (a[0]+a[8]!=a[2]+a[6]) {a[0]++; a[4]++; a[8]++;} }else
if (y>x && y>z) {a[4]=1; a[0]=y-x+1; a[8]=y-z+1;  while (a[0]+a[8]!=a[2]+a[6]) {a[0]++; a[4]++; a[8]++;}} else
{a[8]=1; a[0]=z-x+1; a[4]=z-y+1;  while (a[0]+a[8]!=a[2]+a[6]) {a[0]++; a[4]++; a[8]++;} }
cout<<a[0]<<" "<<a[1]<<" "<<a[2]<<endl<<a[3]<<" "<<a[4]<<" "<<a[5]<<endl<<a[6]<<" "<<a[7]<<" "<<a[8]<<endl;
return 0;
}