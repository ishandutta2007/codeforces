#include<bits/stdc++.h>
using namespace std;
char s[1234567];
int a[1234567];
int v[3];
int ps[4];
int main()
{
	cin >> s;
	int n = strlen(s);
	for(int i = 0;4*i<n;i++)
	{
		ps[0] = 2*i;
		ps[1] = 2*i+1;
		ps[2] = n-2*i-2;
		ps[3] = n-2*i-1;
		for(int k = 0;k<3;k++) v[k] = 0;
		if(ps[3]-ps[0]<3) 
		{
			a[ps[0]] = 1;
			break;
		}
		for(int k = 0;k<4;k++) v[s[ps[k]]-'a'] ++;
		int need;
		for(int k = 0;k<3;k++) if(v[k] == 2) need = k;
		for(int k = 0;k<4;k++) if(s[ps[k]]-'a' == need) a[ps[k]] = 1;		
	}
	for(int i = 0;i<n;i++)
	{
		if(a[i]) printf("%c",s[i]);
	}
	printf("\n");
}