#include<string>
#include <iostream>
using namespace std;
int main ()
{string s[6];
int n; cin>>n; 
s[0]="+------------------------+";
s[1]="|#.#.#.#.#.#.#.#.#.#.#.|D|)";
s[2]="|#.#.#.#.#.#.#.#.#.#.#.|.|";
s[5]="|#.......................|";
s[3]="|#.#.#.#.#.#.#.#.#.#.#.|.|)";
s[4]="+------------------------+";
if(n>2) {s[5][1]='O'; n--;}
for (int i=1; i<22; i+=2)
for (int j=1; j<4; j++)
{if (n>0) {n--; s[j][i]='O';}
}
cout<<s[0]<<endl<<s[1]<<endl<<s[2]<<endl<<s[5]<<endl<<s[3]<<endl<<s[4]<<endl;
//system ("pause");
return 0;
}