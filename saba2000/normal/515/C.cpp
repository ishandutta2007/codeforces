#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
int main ()
{
int n;
string s;
vector <int> k;
cin>>n;
cin>>s;
for (int i=0; i<n; i++)
{
switch(s[i]){
case'2':{k.push_back(2); break;}
case'3':{k.push_back(3); break;}
case'4':{k.push_back(3); k.push_back(2); k.push_back(2); break;}
case'5':{k.push_back(5); break;}
case'6':{k.push_back(5); k.push_back(3); break;}
case'7':{k.push_back(7); break;}
case'8':{k.push_back(7); k.push_back(2);k.push_back(2);k.push_back(2); break;}
case'9':{k.push_back(7); k.push_back(3);k.push_back(3);k.push_back(2);break;}
}
}
sort (k.rbegin(),k.rend());

for (int i=0; i<k.size(); i++)
cout<<k[i];
cout<<endl;

//system ("pause");
return 0;
}