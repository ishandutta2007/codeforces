#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main ()
{
vector <string> v;
vector <int> v1,v2;
int pa[99],ph[99];
string s1,s2;
char ah,yr,w;
int m,n,g;
cin>>s1>>s2;
cin>>g;
int i=0;
while (i<=99)
{pa[i]=0;
ph[i]=0;
i++;}
i=0;
while (i<g)
{cin>>m; cin>>ah; cin>>n; cin>>yr;
if (ah=='a' & yr=='r' & pa[n]<2) pa[n]=2;
if (ah=='h' & yr=='r' & ph[n]<2) ph[n]=2;
if (ah=='a' & yr=='y') pa[n]+=1;
if (ah=='h' & yr=='y' ) ph[n]+=1;
if (pa[n]==2)   {v.push_back(s2); v1.push_back(m); v2.push_back(n); pa[n]=99;}
if (ph[n]==2)   {v.push_back(s1); v1.push_back(m); v2.push_back(n); ph[n]=99;}
i++;
}
i=0;
while (i<v.size())
{
cout<<v[i]<<" "<<v2[i]<<" "<<v1[i]<<endl;
i++;
}

return 0;

}