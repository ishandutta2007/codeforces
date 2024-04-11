#include <bits/stdc++.h>
#include <ctype.h>
using namespace std;

void output(char c)
{
    char k[6] = {'a', 'e', 'i', 'o', 'u', 'y'};
    for(int i=0;i<6;i++)
    {
        if(c == k[i] || c - 'A' + 'a' == k[i])
        {
            cout<<"YES"<<endl;
            return;
        }
    }
    cout<<"NO"<<endl;
    return;
}

int main()
{
	char s[200001];
	cin.getline(s, 200000);
	int l = strlen(s); 
	int l1 = l - 1;
	while(!isalpha(s[l1])) --l1;
	output(s[l1]);
	return 0;
}