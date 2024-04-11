#include <iostream>
#include <string>

using namespace std;

char blah[600000];
string app[600000];
int s[600000];

int main()
{
int n; cin >> n;
for (int i = 0; i < 600000; i++)
blah[i]='Z'+1,app[i] = "";
cin.getline(blah, 600000);
cin.getline(blah, 600000);
int len = 0;
for (;len<600000;len++)
if(blah[len]=='Z'+1)
break;
len--;
blah[len] = ' ';
//for (int i = 0; i < len; i++)
//cout << blah[i];
//cout << len << " " << n*3+(n-1)*4+2*n-2;
if(len!=n*3+(n-1)*4+2*n-2)
{
cout << "Error occurred\n";
return 0;
}
//cout << "negro\n";
int np=0;
int cur = 0;
while (cur < len)
{
//cout << cur << "negro " << s << "\n";
if (blah[cur] == 'p')
{
np++; s[np]=0;
cur+=4;
app[cur]+='<';
}
else
{
cur+=3;
s[np]++;
while(s[np]==2 && np >= 0)
app[cur]+='>',np--,s[np]++;
if (np < 0 || (np == 0 && cur<len) || s[np] >= 3)
{
cout << "Error occurred\n";
return 0;
}
if(cur<len)app[cur]+=',';
}
cur++;
}
for (int i = 0; i <= len; i++) if (blah[i] == ' ') cout << app[i]; else cout << blah[i];
cout << "\n";
return 0;
}